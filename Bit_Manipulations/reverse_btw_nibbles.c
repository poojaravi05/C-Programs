/*
Reverse between nibbles
input:  1011 0101
output: 1101 1010
*/

#include <stdio.h>
#include <stdint.h>

void print_bits(uint8_t num)
{
    int sz = (sizeof(num) * 8) + 1;
    char bits_array[sz];
    bits_array[sz - 1] = '\0';
    uint8_t temp = num;
    
    for (int i = sz - 2; i >= 0; i--)
    {
        bits_array[i] = '0' + (num & 1);
        num = num >> 1;
    }
    
    printf("Num : ( %d ) : Binary representtion: %s\n", temp, bits_array);
}

uint8_t reverse_nibble_bits(uint8_t num)
{
    uint8_t res = 0;
    
    for (int i = 0; i < 4; i++)
    {
        res = (res << 1) | (num & 1);
        num = num >> 1;
    }
    
    return res;
}

uint8_t reverse_nibble(uint8_t num) {
    uint8_t rev_nib = 0;
    for(int i = 0; i < (sizeof(num) * 2); i++) {
        uint8_t nibble = (num >> (i*4)) & 0xF;
        uint8_t rev = reverse_nibble_bits(nibble);
        rev_nib = rev_nib | (rev << (i*4));
    }
    return rev_nib;
}

int main()
{
    int n = 0xb5; // 1011 0101
    int rev_nib = reverse_nibble(n);
    
    printf("n = %02hx, rev_nib = %02hx\n", n, rev_nib);
    print_bits(n);
    print_bits(rev_nib);

    return 0;
}