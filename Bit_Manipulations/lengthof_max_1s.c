// Length of the Longest Consecutive 1s in Binary Representation

#include <stdio.h>
#include <math.h>

int main()
{
    int n = 222, cnt = 0, res = 0;
    
    while(n > 0) {
        if(n & 1 == 1) {
            cnt++;
            res = fmax(res, cnt);
        }
        else {
            cnt = 0;
        }
        n >>= 1;
    }
    printf("Res = %d\n", res);
    return 0;
}
