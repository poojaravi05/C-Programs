/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

uint8_t reverse_bits(uint8_t num)
{
    uint8_t res = 0;
    
    for (int i = 0; i < (sizeof(num) * 8); i++)
    {
        res = (res << 1) | (num & 1);
        num = num >> 1;
    }
    
    return res;
}

int main()
{
    int n = 0x03;
    int rn = reverse_bits(n);
    
    printf("n = %02hx, rn = %02hx\n", n, rn);
    print_bits(n);
    print_bits(rn);

    return 0;
}