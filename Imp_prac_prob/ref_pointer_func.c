#include<stdio.h>
#include<stdlib.h>

int* SumAndProduct(int a, int b, int *sum, int *prod, int *retSz){
    int *res = (int *)calloc(2, sizeof(int));
    *sum = a + b;
    *prod = a * b;
    res[0] = *sum;
    res[1] = *prod;

    *retSz = 2;
    return res;
    //RETURN NULL;
}

int main(){
    int x = 3, y = 5, sum, prod;
    int retSz = 0;
    int *res;
    res = SumAndProduct(x, y, &sum, &prod, &retSz);
    //if (res == NULL)
    //ERROR
    for (int i = 0; i < retSz; i++)
        printf("%d\n", res[i]);
    free(res);
    //printf("The Sum = %d and the Product = %d\n", sum, prod);
    return 0; 
}