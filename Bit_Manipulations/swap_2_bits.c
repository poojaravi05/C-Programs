#include <stdio.h>
#include <stdint.h>

void print_bits(uint32_t n) {
    int size = (sizeof(n)*8) + 1;
    char bits_array[size];
    uint32_t temp = n;
    bits_array[size-1] = '\0';
    for(int i = size-2; i >= 0; i--) {
        bits_array[i] = '0' + (n&1);
        n >>= 1;
    }
    printf("Num: %d, Binary: %s\n", temp, bits_array);
}

uint32_t swap_2_bits(uint32_t n, int p, int q) {
    int bit = ((n >> p) & 1) ^ ((n >> q) & 1);
    
    if(bit == 0) {
        // same bits, no need to swap
        return n;
    } else {
        n = n ^ (1 << p);
        n = n ^ (1 << q);
    }
    return n;
}

int main()
{
    
    uint32_t n = 0x00000057;
    print_bits(n);
    int p = 2, q = 8;
    uint32_t res = swap_2_bits(n, p, q);
    printf("After swapping: %d\n", res);
    print_bits(res);

    return 0;
}