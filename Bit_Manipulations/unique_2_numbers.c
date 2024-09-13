//given an array, where 2 element is not repeating and others repeat twice.

#include <stdio.h>

int find_non_duplicate(int *arr, int sz)
{
    int res = 0, n1 = 0, n2 = 0;
    for(int i = 0; i < sz; i++) {
        res = res ^ arr[i];
    }
    int rightmost_setbit = (res) & (-res);
    for(int i = 0; i < sz; i++) {
        if((arr[i] & rightmost_setbit)!= 0){
            n1 = n1 ^ (arr[i]);
        }
        n2 = res ^ n1;
    }
    printf("2 unique numbers: n1 = %d, n2 = %d\n", n1, n2);
}

int main()
{
    int arr[] = {9, 12, 9, 12, 11, 5, 11, 6};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    find_non_duplicate(arr, sz);
    
    return 0;
}