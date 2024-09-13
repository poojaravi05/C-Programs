#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Returns true if `n` is a power of four
bool checkPowerOf4(unsigned n)
{
    // return true if `n` is a power of 2, and
    // the remainder is 1 when divided by 3
    return !(n & (n - 1))&& (n % 3 == 1);
}

int main()
{
    int n = 20;
    if(checkPowerOf4(n)) {
        printf("The given number is a power of 4");
    }
    else {
        printf("The given number is not a power of 4");
    }
    return 0;
}