#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
int compare(const void* a, const void* b){
    int A = *((int*)a);
    int B = *((int*)b);
    return abs(A) - abs(B);
}

int main(){
    int i, A[] = {-31, 22, -1, 50, -6, 4};
    qsort(A, 6, sizeof(int), compare);
    for(i = 0; i < 6; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
*/

int compare(int a, int b){
    if(a > b) return -1;
    else return 1;
}

int abs_compare(int a, int b){
    if(abs(a) > abs(b)) return 1;
    else return -1;
}

void BubbleSort(int* A, int n, int (*compare)(int, int)){
    int i, j, temp;
    for(i = 0; i < n; i++){
        for(j = 0; i < n-1; j++){
            if(compare(A[j], A[j+1]) > 0){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int i, A[] = {-31, 22, -1, 50, -6, 4};
    BubbleSort(A, 6, compare);
    for(i = 0; i < 6; i++){
        printf("%d ",A[i]);
    }
    return 0;
}
