#include <stdio.h>
#include <stdint.h>
/*
Little Endian - LSB is stored in smaller address
Big Endian - LSB is stored in higher address
LSB - 0x43210 - MSB
*/

//Reverse Endianness - Reverse Bytes
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

uint32_t reverse_bytes(uint32_t num) {
    uint32_t rev_bytes = 0;
    for(int i = 0; i < (sizeof(num)); i++) {
        uint32_t byte = (num >> (i*8)) & 0xFF;
        rev_bytes = rev_bytes | byte << ((sizeof(num) - 1 - i) * 8); //(sizeof(num) - 1 - i gives the index 0 - 3)
    }
    return rev_bytes;
}

/* Another method to swap endianness

uint32_t reverse_bytes(uint32_t num) {
    return ((num & 0x000000ff) << 24) | ((num & 0x0000ff00) << 8) |
          ((num & 0x00ff0000) >> 8) | ((num & 0xff000000) >> 24);
}
*/

int main()
{
    uint32_t n = 0xb59e43c2;
    uint32_t rev_bytes = reverse_bytes(n);
    
    printf("n = %02hx, rev_bytes = %02hx\n", n, rev_bytes);
    print_bits(n);
    print_bits(rev_bytes);

    return 0;
}