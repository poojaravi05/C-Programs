#include <stdio.h>
/*
Little Endian - LSB is stored in smaller address
Big Endian - LSB is stored in higher address
LSB - 0x43210 - MSB
*/
int main()
{
    int x = 0x43210;
    int a = 1;
    char* c = (char*)&x;
    char *p = (char*)&a;
    printf("*p is: 0x%x\n", *p);
    if(*p) {
        printf("Little Endian\n"); //if some value(1), little endian
    }
    else{
        printf("Big Endian\n");
    }

    printf("*c is: 0x%x\n", *c);
    if(*c == 0x10) {
        printf("Little Endian\n");
    }
    else{
        printf("Big Endian\n");
    }
    return 0;
}