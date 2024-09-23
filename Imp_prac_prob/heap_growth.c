#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 5;
    int *res = (int*)malloc(n * sizeof(int));
    if(res == NULL){
        return -1;
    }
    int *ans = (int*)malloc(n * sizeof(int));
    if(ans == NULL){
        free(res);
        return -1;
    }
    printf("res = %p\n", res);
    printf("ans = %p\n", ans);
    if(ans != NULL){
        free(ans);
    }
    if(res != NULL){
        free(res);
    }
    return 0;
}