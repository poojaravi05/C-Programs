#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myMemset(void* ptr, int val, int sz) {
    unsigned char *p = (unsigned char*)ptr;
    while(sz--) {
        *p++ = val;
    }
    return ptr;
}

int main() {
    unsigned char a[10];
    //myMemset(a, 0, 10);
    myMemset(a, 'R', 10);

    for(int i = 0; i < 10; i++) {
        printf("a[%d] = %c\n", i, a[i]);
    }
    return 0;
}
