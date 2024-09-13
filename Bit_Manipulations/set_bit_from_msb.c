// Find most significant set bit of a number

#include <stdio.h>
#include <math.h>

int msb_bit(int n) {
    int cnt = 0, res = 0;
    if(n == 0) {
        return 0;
    }
    while(n > 1) {
        n = n / 2;
        cnt++;
    }
    //res = pow(2, cnt);
    res = 1 << cnt;
    
    return res;
}

int main() {
    int n = 18, res = 0;
    res = msb_bit(n);
    printf("Res = %d\n", res);
    return res;
}
