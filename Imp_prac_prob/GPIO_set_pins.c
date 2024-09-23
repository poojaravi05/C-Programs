// Example program to set pin 15 of GPIOA to 1

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Volatile for register values. Hardware may change its value at any time
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define GPIO register structure
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
    volatile uint32_t BRR;
    volatile uint32_t ASCR;  
} GPIO_REG;

// Define GPIO port addresses
#define GPIO_A ((GPIO_REG*) 0x48000000)

// Function to check if a specific GPIO pin is set (high)
int is_gpio_pin_set(uint8_t pin_num, GPIO_REG *gpio_port) {
    if (pin_num > 31) {
        printf("Error: Invalid pin number (%d)\n", pin_num);
        return -1;
    }

    uint32_t pin_mask = (1UL << pin_num);
    printf("Checking pin %d with mask 0x%08X\n", pin_num, pin_mask);

    if ((gpio_port->ODR & pin_mask) != 0) {
        printf("Pin %d is set (high)\n", pin_num);
        return 1;
    } else {
        printf("Pin %d is clear (low)\n", pin_num);
        return 0;
    }
}

int main() {
    GPIO_A->ODR |= 1UL << 15;

    int pin_state = is_gpio_pin_set(15, GPIO_A);
    if (pin_state == 1) {
        printf("Pin 15 of GPIOA is set (high)\n");
    } else if (pin_state == 0) {
        printf("Pin 15 of GPIOA is clear (low)\n");
    } else {
        printf("Error checking pin state\n");
    }

    return 0;
}
