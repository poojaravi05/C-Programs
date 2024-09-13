// Flip or Invert or Toggle

#include <stdio.h>
#include <math.h>

int cnt_bits(int n) {
    int cnt = 0;
    while(n > 0) {
        cnt++;
        n >>= 1;
    }
    return cnt;
}

// calculating number of bits in the number 
// int x = log2(num) + 1;

int flip_bit(int n) {
    int cnt = cnt_bits(n);
    int i = 0;
    while(i < cnt) {
        n = n ^ (1 << i);
        i++;
    }
    return n;
}

int main() {
    int n = 11, res = 0;
    res = flip_bit(n);
    printf("Res = %d\n", res);
    return res;
}
