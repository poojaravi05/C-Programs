// Find the absolute value of a number
#include <stdio.h>

int main() {
    int n = -12, absolute = 0;
    int mask = n >> 31;
    
    absolute = (n + mask) ^ mask;
    printf("The absolute value of the given number is %d", absolute);
    return 0;
}