// find the previous power of 2. If n itself is a power of 2, return n.

#include <stdio.h>

int power_of_2(int n) {
    while((n & n-1) != 0) {
        n = n & n-1; // do this until there is only 1 bit set
    }
    return n; // to get previous number with power of 2
}

int main() {
    int n = 7, ans = 0;
    ans = power_of_2(n);
    printf("The power of 2 number is %d", ans);
    
    return 0;
}