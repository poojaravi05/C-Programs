#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct __attribute__((packed)) dob {
    unsigned int d:5; //date takes value only from 1 to 31 and 5 bits are sufficient to represent it.
    unsigned int m:4;
    unsigned int y;
} dob_t;

typedef struct __attribute__((packed)) read_bits {
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char n;
} read_bits_t;


typedef struct __attribute__((packed)) short_nibbles {
    unsigned short nibble0:4;
    unsigned short nibble1:4;
    unsigned short nibble2:4;
    unsigned short nibble3:4;
} short_nibbles_t;


int main()
{
    dob_t emp[10];
    
    printf("Sizeof dob_t = %lu and Sizeof emp = %lu\n", sizeof(dob_t), sizeof(emp));
    
    read_bits_t rb[10];
    printf("Sizeof read_bits_t = %lu and Sizeof rb = %lu\n", sizeof(read_bits_t), sizeof(rb));
    
    short_nibbles_t sh[4];
    printf("Sizeof short_nibbles_t = %lu and Sizeof sh = %lu\n", sizeof(short_nibbles_t), sizeof(sh));
    
    unsigned short num = 0xabcd;
    for (int i = 0; i < 4; i++)
    {
        memcpy(&sh[i], &num, sizeof(short_nibbles_t));
    }
    
    for (int i = 0; i < 4; i++)
    {
        printf("Sh[%d].nibble3 = %01x, Sh[%d].nibble2 = %01x, Sh[%d].nibble1 = %01x, Sh[%d].nibble0 = %01x\n",
                i , sh[i].nibble3, i, sh[i].nibble2, i, sh[i].nibble1, i, sh[i].nibble0);
    }
    
    int idx;
    printf("Enter the nibble index: ");
    scanf("%d", &idx);
    
    unsigned short nibble = idx % 4;
    idx = idx / 4;
    
    switch(nibble)
    {
        case 0:
            printf("The required nibble is: %01x\n", sh[idx].nibble0);
            break;
        case 1:
            printf("The required nibble is: %01x\n", sh[idx].nibble1);
            break;
        case 2:
            printf("The required nibble is: %01x\n", sh[idx].nibble2);
            break;
        case 3:
            printf("The required nibble is: %01x\n", sh[idx].nibble3);
            break;
        default:
            break;
    }
    
    return 0;
}