// Find the postion of the only set bit

#include <stdio.h>

int main()
{
    int n = 4, cnt = 0;
    
    while(n) {
        cnt++;
        n >>= 1;
    }
    printf("Position of set bit is %d", cnt);
    
    return 0;
}
