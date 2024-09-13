#include <stdio.h>

void check_bit_set(int num, int pos) {
    if((num & (1 << (pos-1))) != 0) {
        printf("The bit %d of the number %d in binary is set", pos, num);
    }
    else {
        printf("The bit %d of the number %d in binary is not set", pos, num);
    }
}

int main() {
    int num = 13, pos = 2;
    check_bit_set(num, pos);
    
    return 0;
}

/*
#include <stdio.h>
#include <stdbool.h>

bool isKthBitSet(int n, int k) {
    return (n & (1 << (k - 1))) != 0;
}

int main() {
    int n = 13;
    int k = 3;
 
    if (isKthBitSet(n, k)) {
        printf("k'th bit is set");
    }
    else {
        printf("k'th bit is not set");
    }
 
    return 0;
}
*/