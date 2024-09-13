// Turn off/unset the rightmost set bit

#include <stdio.h>
#include <stdint.h>

uint32_t unset_right_bit(uint32_t num) {
    return (num & (num - 1));
}

int main() {
    uint32_t num = 0x1010;
    
    printf("After unsetting the 1st set right bit is %x\n", unset_right_bit(num));
    
    return 0;
}
