// Flip or Invert or Toggle

#include <stdio.h>
#include <math.h>

int flip_bit(int num, int n) {
    num = num ^ (1 << n);

    // num = num & (~(1 << (n-1))); -> to turn off the nth bit
    // num = num | (~(1 << (n-1))); -> to turn on the nth bit
    
    return num;
}

int main() {
    int num = 11, res = 0;
    res = flip_bit(num, 3);
    printf("Res = %d\n", res);
    return res;
}
