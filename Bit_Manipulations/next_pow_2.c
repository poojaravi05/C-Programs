// find the next highest power of 2. If n itself is a power of 2, return n.

#include <stdio.h>

int power_of_2(int n) {
    n = n-1; // to handle base case if num itself is power of 2
    while((n & n-1) != 0) {
        n = n & n-1; // do this until there is only 1 bit set
    }
    return n << 1; // to get next number with power of 2
}

int main() {
    int n = 20, ans = 0;
    ans = power_of_2(n);
    printf("The power of 2 number is %d", ans);
    
    return 0;
}