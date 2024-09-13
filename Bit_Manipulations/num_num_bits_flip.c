// Find the total number of bits needed to be flipped to convert a given integer to another.

#include <stdio.h>

int main()
{
    int n1 = 65, n2 = 80;
    int cnt = 0, ans = 0;
    
    ans = n1 ^ n2;
    
    while(ans) {
        if(ans & 1 == 1) {
            cnt++;
        }
        ans >>= 1;
    }
    printf("The number bits to be flipped = %d", cnt);
    return cnt;
}