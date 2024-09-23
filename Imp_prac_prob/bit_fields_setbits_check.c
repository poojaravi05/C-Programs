#include <stdio.h>

typedef union ch_bits {
    struct {
        unsigned char bit0:1;
        unsigned char bit1:1;
        unsigned char bit2:1;
        unsigned char bit3:1;
        unsigned char bit4:1;
        unsigned char bit5:1;
        unsigned char bit6:1;
        unsigned char bit7:1;
    } char_bits;
    unsigned char ch;
}ch_bits_u;

int main()
{
    ch_bits_u u;
    
    u.ch = 'G';
    
    printf("u.ch = %c\n", u.ch);
    
    int bit;
    printf("Enter bit value b/w 0 to 7: ");
    scanf("%d", &bit);
    
    printf("bit %d = %d\n", bit, u.char_bits.bit5 & 1 ? 1 : 0);
    

    return 0;
}