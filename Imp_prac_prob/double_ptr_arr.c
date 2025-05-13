#include <stdio.h>
#include <stdlib.h>

int g_arr[3] = {1, 2, 3};

void print_arr(int* arr, int sz) {
    for(int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void process_arr_double(int** arr, int sz) {
    
    *arr = g_arr;
    
    printf("Entering %s: ", __func__);
    printf("Before processing: ");
    print_arr(*arr, sz);
    
    for(int i = 0; i < sz; i++) {
        (*arr)[i] += 10;
    }
    printf("After processing: ");
    print_arr(*arr, sz);
    
    return;
}

void process_arr_single(int* arr, int sz) {
    
    arr = g_arr; // local scope with single ptr
    //the processed value would get updated even with single ptr,
    //if it was just arr and not arr = g_arr
    //updated value with same address will be reflected.
    
    printf("Entering %s: ", __func__);
    printf("Before processing: ");
    print_arr(arr, sz);
    
    for(int i = 0; i < sz; i++) {
        arr[i] += 10;
    }
    printf("After processing: ");
    print_arr(arr, sz);
    
    return;
}

int main() {
    int sz = 3;
    int* arr = (int*)calloc(sz, sizeof(int));
    if(!arr) {      //if(arr == NULL)
        printf("Mem not allocated\n");
    }
    
    arr[0] = 4;
    arr[1] = 5;
    arr[2] = 6;
    
    printf("Output 1: Single pointer\n");
    printf("Entering %s: ", __func__);
    print_arr(arr, sz);
    
    process_arr_single(arr, sz);
    
    printf("Entering %s: ", __func__);
    print_arr(arr, sz);

    printf("\n");

    printf("Output 2: Double pointer\n");
    printf("Entering %s: ", __func__);
    print_arr(arr, sz);
    
    process_arr_double(&arr, sz);
    
    printf("Entering %s: ", __func__);
    print_arr(arr, sz);
    
    free(arr);
    
    return 0;
}

/*
output:
------- 
Output 1: Single pointer
Entering main: 4 5 6
Entering process_arr_single: Before processing: 1 2 3
After processing: 11 12 13
Entering main: 4 5 6

Output 2: Double pointer
Entering main: 4 5 6
Entering process_arr_double: Before processing: 11 12 13
After processing: 21 22 23
Entering main: 21 22 23
*/
