#include <stdio.h>

int main() {
    int n = 6;
    int res = n & 3; // remainder of n, when divided by 4.
    //Here, 3 is the mask, becuase 4 has 2 bits 0 to LSB, which is 3 in value.
    
    //Find remainder of A when divided by x, which is a power of 2.
    int a = 12, x = 8;
    int r = a & (x-1);
    
    printf("Remainder: %d\n", res);
    printf("Remainder: %d", r);
    
    return 0;
}