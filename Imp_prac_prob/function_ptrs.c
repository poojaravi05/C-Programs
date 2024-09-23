#include<stdio.h>
#include<stdlib.h>

int add(int x, int y){
    return x+y;
}

void print(char* name){
    printf("Hello %s\n", name);
}

int main(){
    int c;
    int (*p)(int, int); //(*p) is a function pointer
    //int* p(int, int) //the function is of return type pointer
    p = &add;
    c = (*p)(2, 3);
    printf("Sum = %d\n", c);
    
    void (*ptr)(char*);
    ptr = print;
    ptr("Pooja");
    
    return 0;
}