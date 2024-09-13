// Count bits wiith lookup table

#include <stdio.h>

int main()
{
    int n = 222, cnt = 0;
    
    while(n > 0) {
        if(n & 1 == 1) {
            cnt++;
        }
        n >>= 1;
    }
    printf("Res = %d\n", cnt);
    return 0;
}

// using Brian Kernighan’s algorithm
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
    return count;
}

