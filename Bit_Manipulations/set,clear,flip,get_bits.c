//set bit, clear bit, flip bit, retrieve bit

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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

uint32_t set_bit(uint32_t n, int pos) {
    return (n | (1 << (pos-1)));
}

uint32_t clear_bit(uint32_t n, int pos) {
    return (n & (~(1 << pos-1)));
}

uint32_t flip_bit(uint32_t n, int pos) {
    return (n ^ (1 << pos-1));
}

bool retrieve_bit(uint32_t n, int pos) {
    bool res = n & (1 << (pos-1));
    return res;
}

int main()
{
    uint32_t n = 0x0000000a;
    print_bits(n);
    uint32_t p = set_bit(n, 2);
    print_bits(p);
    uint32_t q = clear_bit(n, 2);
    print_bits(q);
    uint32_t r = flip_bit(n, 2);
    print_bits(r);
    uint32_t s = retrieve_bit(n, 2);
    print_bits(s);

    return 0;
}