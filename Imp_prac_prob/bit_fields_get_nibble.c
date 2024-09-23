#include <stdio.h>

typedef union ch_bits {
    struct {
        unsigned char nibble0:4;
        unsigned short nibble1:4;
        unsigned short nibble2:4;
        unsigned short nibble3:4;
    } short_nibbles;
    unsigned short sh;
}sh_nibble_u;

int main()
{
    sh_nibble_u u;
    
    u.sh = 0xabcd;
    
    printf("u.sh = %04x, u.short_nibbles.nibble0: %01x,"\
           "u.short_nibbles.nibble1: %01x, u.short_nibbles.nibble2: %01x, "\
           " u.short_nibbles.nibble3: %01x,\n",
           u.sh, u.short_nibbles.nibble0, u.short_nibbles.nibble1, u.short_nibbles.nibble2,
           u.short_nibbles.nibble3);
    

    return 0;
}