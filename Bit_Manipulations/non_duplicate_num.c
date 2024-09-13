//given an array, where only one element is not repeating and others repeat twice.

#include <stdio.h>

int find_non_duplicate(int *arr, int sz)
{
    int res = 0;
    for(int i = 0; i < sz; i++) {
        res = res ^ arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 3, 4, 4};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    int non_dup_num = find_non_duplicate(arr, sz);
    printf("The missing number in the array is: %d\n", non_dup_num);
    return 0;
}