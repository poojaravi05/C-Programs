#include<stdio.h>
#include<stdlib.h>

int* add(int* x, int* y){
    int* z = (int*)malloc(sizeof(int));
    *z = (*x) + (*y);
    return z;
}

int main(){
    int a = 2, b = 4;
    int* c = add(&a, &b);
    printf("Sum = %d", *c);
    return 0;
}