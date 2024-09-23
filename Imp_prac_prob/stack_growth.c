#include<stdio.h>
#include<stdlib.h>

void determine_stack_growth(int* ptr){
    int b;
    printf("Local = %p\n", &b);
    printf("Main = %p\n", ptr);
    if(ptr > &b){
        printf("Stack is growing downwards\n");
    }
    else{
        printf("Stack is growing upwards\n");
    }
    
}

int main(){
    int a;
    determine_stack_growth(&a);
    return 0;
}