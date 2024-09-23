#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n){
    //0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ......
    int n1 = 0, n2 = 1;
    for(int i = 0; i < n-2; i++){
        int k = n2;
        n2 = n1+n2;
        n1 = k;
    }
    printf("The %dth element in Fibonacci series is %d\n", n, n2);
    return n2; //cannot return if the function return type is void
}

int main(){
    int r = fibonacci(7);
    printf("The 7th element in Fibonacci series is %d\n", r);
    fibonacci(12);
    fibonacci(4);
    
    return 0;
}