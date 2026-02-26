/**
 * Packs thermal data into a 16-bit packet.
 * [Sensor ID: 4 bits] [Temperature: 11 bits] [Fan State: 1 bit]
 */

#include <stdio.h>
#include <stdint.h>

uint16_t pack_thermal_telemetry(uint8_t id, uint16_t temperature, uint8_t fan_on) {
    uint16_t packet = 0;

    // 1. Pack Sensor ID (bits 12-15)
    packet |= (id & 0x0F) << 12;

    // 2. Pack Temperature (bits 1-11)
    /*
    // We add an offset to handle negative temps (e.g., -50 becomes 0)
    //We cannot directly store negative numbers in an unsigned field.
    //We shift the entire temperature range upward so that the lowest possible temperature becomes zero.
    //If minimum temp = -50°C, then temp + 50. offset = -temp
    //Now everything is positive → fits in unsigned 11 bits.
    */
    uint16_t temp_offset = (temperature + 50) & 0x07FF;
    packet |= (temp_offset) << 1;

    // 3. Pack Fan State (bit 0)
    packet |= (fan_on & 0x01);
    
    return packet;
}

void print_bits(uint16_t num) {
    int sz = (sizeof(num) * 8) + 1;
    char bits_array[sz];
    bits_array[sz-1] = '\0';
    uint16_t tmp = num;
    for(int i = sz-2; i >= 0; i--) {
        bits_array[i] = '0' + (num & 1);
        num >>= 1;
    }
    printf("Num: %d, Binary: %s\n", tmp, bits_array);
}

int main() {
    uint8_t id = 12;
    uint8_t fan_status = 1;
    uint16_t temp = 75;
    
    print_bits(id);
    print_bits(fan_status);
    print_bits(temp);
    
    uint16_t packet = pack_thermal_telemetry(id, temp, fan_status);
    print_bits(packet);
    return 0;
}
