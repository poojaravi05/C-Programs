// Signness check for 2 numbers

#include <stdio.h>

int main() {
    int num1 = 4, num2 = -7;
    
    //XOR gives 1 if 2 inputs are different. As MSB indicates sign (1 - neg, 0 - pos).
    //After XORing, if the fisrt bit from left is 1 (indicating < 0), meaning different bits.
    //If XOR operation results in 0, the bits are same.
    if((num1 ^ num2) < 0) {
        printf("The numbers have different sign");
    }
    else {
        printf("The numbers have same sign");
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool sign_diff(int num1, int num2) {
    if((num1 ^ num2) < 0) {
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int a = -3, b = 2;
    bool res;
    res = sign_diff(a, b);
    printf("Is the given two numbers have opposite sign? %d", res);
    
    return 0;
    
}

*/