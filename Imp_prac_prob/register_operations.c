#include <stdint.h>

// Example: A thermal control register at hex address 0x40001000
#define THERMAL_CTRL_REG_ADDR  0x40001000 

// Define a macro for easy access. 
// 'volatile' is mandatory so the compiler doesn't "optimize away" the access.
#define THERMAL_CTRL_REG  (*(volatile uint32_t *)THERMAL_CTRL_REG_ADDR)

//READ from register
uint32_t read_thermal_status(void) {
    // 1. Simple Read: Fetches all 32 bits from hardware
    uint32_t reg_val = THERMAL_CTRL_REG;

    // 2. Masking: Use bitwise AND (&) to isolate the bits you want.
    // Let's say bits 0-7 are the temperature value (0xFF).
    uint32_t temp = reg_val & 0xFF;

    return temp;
}

//WRITE to register
//1. Setting a Bit (Changing a 0 to 1)
void enable_fan(void) {
    // Assume Bit 15 is the "Fan Enable" bit
    // (1 << 15) creates a "mask" where only the 15th bit is a 1.
    THERMAL_CTRL_REG |= (1 << 15); 
}

//2. Clearing a Bit (Changing a 1 to 0)
void disable_fan(void) {
    // This flips the bits (all 1s, but 0 at bit 15) and ANDs it.
    THERMAL_CTRL_REG &= ~(1 << 15);
}

//3. Writing a Multi-bit Value (The "Safe" Way)
//If you want to set bits 4–7 to a specific value without touching anything else:
void set_fan_speed(uint8_t speed) {
    uint32_t mask = (0xF << 4); // 0xF is 1111 in binary, shifted to bits 4-7
    
    uint32_t current_val = THERMAL_CTRL_REG;      // 1. READ
    current_val &= ~mask;                         // 2. MODIFY (Clear target bits)
    current_val |= ((uint32_t)speed & 0xF) << 4;  // 2. MODIFY (Insert new bits)
    THERMAL_CTRL_REG = current_val;               // 3. WRITE
}
