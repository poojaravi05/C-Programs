/*
Timers usually live at a specific physical address defined in the SoC (System on Chip) datasheet.
If your timer is 32-bit, reading it is as simple as accessing the variable.
*/
#include <stdint.h>

// Example: System Timer Low Register at 0x40002000
#define SYSTEM_TIMER_REG_ADDR  0x40002000

// Define as a volatile pointer to force a fresh hardware read every time
#define SYSTEM_TIMER_LOW (*(volatile uint32_t *)SYSTEM_TIMER_REG_ADDR)

uint32_t get_ticks(void) {
    return SYSTEM_TIMER_LOW; // Single bus transaction
}
