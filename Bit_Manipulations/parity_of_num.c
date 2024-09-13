// Parity - number of one's in a binary form of a number
// Even parity - 1 appears even times
// Odd parity - 1 appears odd times

#include <stdio.h> 

int parity(int n) {
    int cnt = 0;
    while(n) {
        if(n & 1 == 1) {
            cnt++;
        }
        n >>= 1;
    }
    return cnt;
}

/*
int findParity(int x)
{
    // recursively divide the (32–bit) integer into two equal
    // halves and take their XOR until only 1 bit is left
 
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
        or
    x = (x & 0x0000FFFF) ^ (x >> 16);
    x = (x & 0x000000FF) ^ (x >> 8);
    x = (x & 0x0000000F) ^ (x >> 4);
    x = (x & 0x00000003) ^ (x >> 2);
    x = (x & 0x00000001) ^ (x >> 1);

    // return 1 if the last bit is set; otherwise, return 0
    return x & 1;
}
*/

int even_odd_parity(int n) {
    bool parity = false;
    while(n) {
        if(n & 1 == 1) {
            parity = !parity;
        }
        n >>= 1;
    }
    return parity;
}

int main() {
    int n = 14;
    int cnt = parity(n);
    printf("Total number of 1's (parity) in %d is %d\n", n, cnt);
    
    bool parity = even_odd_parity(n);
    if(parity == true) {
        printf("The parity of %d is odd", n);
    }
    else {
        printf("The parity of %d is even", n);
    }
    return 0;
}