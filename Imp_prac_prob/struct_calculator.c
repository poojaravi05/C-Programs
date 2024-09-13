#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    int res = a+b;
    if(res < a || res < b) {
        printf("Overflow");
        return -1;
    }
    return res;
}

int sub(int a, int b) {
    int res = a-b;
    return res;
}

int mul(int a, int b) {
    int res = a*b;
    if(res < a || res < b) {
        printf("Overflow");
        return -1;
    }
    return res;
}

typedef struct qurem {
    int quo;
    int rem;
} qurem;

qurem divi(int a, int b) {
    qurem res;
    res.quo = a/b;
    res.rem = a%b;
    
    return res;
    
}

int main() {
    int res = 0;
    res = add(1, 2);
    printf("Addition res = %d\n", res);
    res = sub(5, 3);
    printf("Subtraction res = %d\n", res);
    res = mul(2, 3);
    printf("Multiplication res = %d\n", res);
    qurem ans = divi(10, 3);
    printf("Division quo = %d, rem = %d\n", ans.quo, ans.rem);
    
    return 0;
}