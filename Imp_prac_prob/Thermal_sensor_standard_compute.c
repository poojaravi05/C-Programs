#include <stdio.h>
#include <stdint.h>
#include <stdatomic.h>
#include <limits.h>

/* * 1. MEMORY ALIGNMENT & FIXED WIDTH TYPES
 * Ordered largest to smallest to minimize padding.
 */
#define BUFF_SIZE 4
#define MASK (BUFF_SIZE - 1)

typedef struct sensor_info {
    int32_t buffer[BUFF_SIZE];   // 16 bytes
    _Atomic int32_t total;       // 4 bytes - Atomic for thread safety
    _Atomic int32_t min;         // 4 bytes
    _Atomic int32_t max;         // 4 bytes
    uint32_t wr_ptr;             // 4 bytes
    uint32_t cnt;              // 4 bytes
} sensor_info_t;

/* * 2. VOLATILE KEYWORD
 * Ensures the compiler doesn't cache the struct in registers if an ISR modifies it.
 */
static volatile sensor_info_t my_info = {
    .wr_ptr = 0,
    .cnt = 0,
    .min = INT32_MAX,
    .max = INT32_MIN,
    .total = 0
};

/* * 3. DETERMINISTIC MIN/MAX UPDATES
 * These are called only when the extreme value is being evicted.
 */
static int32_t update_min(uint32_t idx) {
    int32_t current_min = INT32_MAX;
    for (uint32_t i = 0; i < BUFF_SIZE; i++) {
        if (i != idx && my_info.buffer[i] < current_min) {
            current_min = my_info.buffer[i];
        }
    }
    return current_min;
}

static int32_t update_max(uint32_t idx) {
    int32_t current_max = INT32_MIN;
    for (uint32_t i = 0; i < BUFF_SIZE; i++) {
        if (i != idx && my_info.buffer[i] > current_max) {
            current_max = my_info.buffer[i];
        }
    }
    return current_max;
}

/* * 4. WRITE VALUE WITH SATURATION & ATOMICS
 */
void write_val(int32_t val) {
    int32_t oldest_val = my_info.buffer[my_info.wr_ptr];
    int32_t current_total = atomic_load(&my_info.total);
    int64_t next_total = 0;

    if (my_info.cnt >= BUFF_SIZE) {
        // OVERWRITE CASE
        
        // Accurate Min Tracking: If we lose the old min, find the new one
        if (oldest_val == atomic_load(&my_info.min) && val > oldest_val) {
            atomic_store(&my_info.min, update_min(my_info.wr_ptr));
        }
        
        // Accurate Max Tracking: If we lose the old max, find the new one
        if (oldest_val == atomic_load(&my_info.max) && val < oldest_val) {
            atomic_store(&my_info.max, update_max(my_info.wr_ptr));
        }

        /* * 5. INTEGRAL ANTI-WINDUP / SATURATION CHECK
         * We use a 64-bit temporary variable to check if the new total 
         * would exceed the 32-bit limits of our 'total' storage.
         */
        next_total = (int64_t)current_total - oldest_val + val;
    }
    else {
        // FILLING CASE
        my_info.cnt++;
        // Check for overflow during initial fill
        next_total = (int64_t)current_total + val;
    }
    
    //update total
    if (next_total > INT32_MAX) {
        current_total = INT32_MAX; // Saturate High
    }
    else if (next_total < INT32_MIN) {
        current_total = INT32_MIN; // Saturate Low
    }
    else {
        current_total = (int32_t)next_total;
    }
    atomic_store(&my_info.total, current_total);

    // Update extremes if new value is a new min/max
    if (val < atomic_load(&my_info.min))
        atomic_store(&my_info.min, val);
    if (val > atomic_load(&my_info.max))
        atomic_store(&my_info.max, val);

    // Write to buffer and increment pointer
    my_info.buffer[my_info.wr_ptr] = val;
    my_info.wr_ptr = (my_info.wr_ptr + 1) & MASK;
}

void print_buff(void)
{
    printf("************************************************\n");
    for (int i = 0 ; i < my_info.cnt; i++)
    {
        printf("%d  ", my_info.buffer[i]);
    }
    printf("\n************************************************\n");
}

void print_bits(uint32_t num)
{
    int sz = (sizeof(num) * 8) + 1;
    char bits_array[sz];
    bits_array[sz - 1] = '\0';
    uint32_t temp = num;
    
    for (int i = sz - 2; i >= 0; i--)
    {
        bits_array[i] = '0' + (num & 1);
        num = num >> 1;
    }
    
    printf("Num : ( %d ) : Binary representtion: %s\n", temp, bits_array);
}

/* * 6. BIT-PACKING FOR TELEMETRY (BIG DATA)
 * Squeezes data into a single 32-bit packet.
 * [8-bit Min] [8-bit Max] [8-bit Avg] [8-bit Padding/Status]
 */

uint32_t pack_telemetry_data(void) {
    int32_t current_total = atomic_load(&my_info.total);
    //print_bits(current_total);

    int32_t avg = (my_info.cnt > 0) ? (current_total / my_info.cnt) : 0;
    //print_bits(avg);

    // Shift temperatures to unsigned range (assuming -50C to 150C)
    uint8_t p_min = (uint8_t)(atomic_load(&my_info.min) + 50);
    print_bits(p_min);
    uint8_t p_max = (uint8_t)(atomic_load(&my_info.max) + 50);
    print_bits(p_max);
    uint8_t p_avg = (uint8_t)(avg + 50);
    print_bits(p_avg);
    uint8_t p_total = (uint8_t)(atomic_load(&my_info.total) + 50);
    print_bits(p_total);

    uint32_t packet = 0;
    packet |= (uint32_t)p_min << 24;
    packet |= (uint32_t)p_max << 16;
    packet |= (uint32_t)p_avg << 8;
    packet |= (uint32_t)p_total;
    
    return packet;
}

uint8_t extract_data(uint32_t packet, int op) {
    //0-7 = total(1), 8-15 = avg(2), 16-23 = max(3), 24-31 = min(4)
    switch(op) {
        case 1:
            printf("\n Total: ");
            return (packet & 0xFF);
            break;
        case 2:
            printf("\n Avg: ");
            return (packet >> 8) & 0xFF;
            break;
        case 3:
            printf("\n Max: ");
            return (packet >> 16) & 0xFF;
            break;
        case 4:
            printf("\n Min: ");
            return (packet >> 24) & 0xFF;
            break;
        default:
            printf("Invalid option\n");
    }
    return 1;
}

/* * 7. THREAD-SAFE GETTERS
 */
int32_t get_min(void) {
    return atomic_load(&my_info.min);
}

int32_t get_max(void) {
    return atomic_load(&my_info.max);
}

int32_t get_avg(void) { 
    return (my_info.cnt > 0) ? (atomic_load(&my_info.total) / my_info.cnt) : 0; 
}

int32_t get_total(void) {
    return atomic_load(&my_info.total);
}

int32_t get_count(void) {
    return my_info.cnt;
}


int main() {
    write_val(11);
    write_val(12);
    write_val(13);
    write_val(14);
    
    print_buff();
    
    printf("Min: %d\n", get_min());
    printf("Max: %d\n", get_max());
    printf("Current Cnt: %d\n", get_count());
    printf("Total: %d\n", get_total());
    printf("Avg: %d\n", get_avg());
    
    write_val(15);
    
    print_buff();
    
    printf("Min: %d\n", get_min());
    printf("Max: %d\n", get_max());
    printf("Current Cnt: %d\n", get_count());
    printf("Total: %d\n", get_total());
    printf("Avg: %d\n", get_avg());
    
    write_val(16);
    print_buff();
    
    printf("Min: %d\n", get_min());
    printf("Max: %d\n", get_max());
    printf("Current Cnt: %d\n", get_count());
    printf("Total: %d\n", get_total());
    printf("Avg: %d\n", get_avg());
    
    write_val(1);
    print_buff();
    
    printf("Min: %d\n", get_min());
    printf("Max: %d\n", get_max());
    printf("Current Cnt: %d\n", get_count());
    printf("Total: %d\n", get_total());
    printf("Avg: %d\n", get_avg());
    
    write_val(100);
    print_buff();
    
    printf("Min: %d\n", get_min());
    printf("Max: %d\n", get_max());
    printf("Current Cnt: %d\n", get_count());
    printf("Total: %d\n", get_total());
    printf("Avg: %d\n", get_avg());
    
    uint32_t telemetry = pack_telemetry_data();
    printf("Packed Telemetry Packet: 0x%08X\n", telemetry);

    print_bits(telemetry);

    uint8_t total = extract_data(telemetry, 1);
    uint8_t total_temp = total - 50;
    printf("Actual temp = %d\n", total_temp);

    return 0;
}