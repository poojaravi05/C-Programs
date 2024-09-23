#include<stdio.h>

int missingEle(int arr[], int n){
    int total = 0, curr_sum = 0;
    total = ((n+1)*(n+2))/2;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
    }
    return total - curr_sum;
}

int main(){
    int res = 0;
    int n = 4;
    int arr[] = {1, 2, 3, 5};
    res = missingEle(arr, n);
    printf("%d", res);
    return 0;
}