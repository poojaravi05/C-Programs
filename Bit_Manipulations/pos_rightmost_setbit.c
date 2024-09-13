#include <stdio.h> 

int rightmost_setbit(int n) {
    int pos = 0;
    if(n & 1 == 1) {
        return 1;
    }
    n = n ^ (n & (n-1));
    while(n) {
        n >>= 1;
        pos++;
    }
    return pos;
}

int main() {
    int n = 14;
    int pos = rightmost_setbit(n);
    printf("The rightmost set bit is in %d position", pos);
    return 0;
}