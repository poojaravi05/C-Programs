/*
To prevent "corrupted" time values, you must use a loop to ensure the HIGH bits didn't change while you were reading the LOW bits.
*/
#define TIMER_HIGH_REG (*(volatile uint32_t *)0x40002004)
#define TIMER_LOW_REG  (*(volatile uint32_t *)0x40002000)

uint64_t get_system_time_64(void) {
    uint32_t high1, high2, low;

    do {
        high1 = TIMER_HIGH_REG; // Read high bits first
        low   = TIMER_LOW_REG;  // Read low bits
        high2 = TIMER_HIGH_REG; // Read high bits again
    } while (high1 != high2);   // Repeat if a rollover occurred

    return ((uint64_t)high1 << 32) | low;
}
