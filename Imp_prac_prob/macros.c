#include <stdio.h>

//macros
#define SIZE 5
#define PRODUCT(X, Y) X*Y
//to define macros in next line use "\"
#define PRINT_VAR(X)\
    printf(#X " is %d at address %p\n", X, &X)
#define SWAP(A, B) A^=B^=A^=B
#define PATTERN "My name is "
const int max = 100;

int main(int argc, char *argv){
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = i*2;
        printf("%d\n", arr[i]);
    }
    int a = 3, b = 4;
    printf("Product of %d and %d = %d\n", a, b, PRODUCT(a, b)); //12
    printf("Product of %d and %d = %d\n", a, b, PRODUCT(2, b)); //8
    printf("Product of %d and %d = %d\n", a, b, PRODUCT(a + 1, b)); //7,which is wrong-order of operation isn't specified.
    //to fix this, enclose the parameters of the macros. #define PRODUCT(X, Y) (X)*(Y). Output will be 16 now.

    PRINT_VAR(a);

    printf("a = %d and b = %d\n", a, b);
    SWAP(a, b);
    printf("a = %d and b = %d\n", a, b);

    printf(PATTERN"Pooja\n");
    //printf(SIZE); //warning: passing argument 1 of 'printf' makes pointer from integer without a cast
    printf("%d\n", SIZE);
    printf("%d\n", max);
    return 0;
}

