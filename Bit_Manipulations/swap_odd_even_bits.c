// Swap all odd and even bits

#include <stdio.h>
#include <stdint.h>

uint32_t swap_bits(uint32_t num) {
    uint32_t even_odd = (num & 0xaaaaaaaa) >> 1;
    uint32_t odd_even = (num & 0x55555555) << 1;
    
    return (even_odd | odd_even);
}

int main()
{
    uint32_t num = 0xa;
    
    printf("The original number is %x\n", num);
    printf("The swapped number is %x\n", swap_bits(num));
    
    
    return 0;
}