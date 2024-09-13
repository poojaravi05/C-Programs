#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    int ans = 0, res = 0;
    for(int i = 31; i >= 0; i--) {
        res = (n & 1) << i;
        ans |= res;
        n >>= 1;
    }
    printf("Number after reversing: %d\n", ans);
    return ans;
}

int main() {
    uint32_t n = 14;
    printf("Number before reversing: %d\n", n);
    reverseBits(n);
}

/*
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    return n;
}
*/
