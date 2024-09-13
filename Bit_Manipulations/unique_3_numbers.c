//given an array, where 3 element(x, y, z) is not repeating and others repeat twice.
//x is pow of 2, y is multiple of x, z is smaller than x and y.

#include <stdio.h>

int find_non_duplicate(int *arr, int sz)
{
    int res = 0, res2 = 0, n1 = 0, n2 = 0, n3 = 0;
    for(int i = 0; i < sz; i++) {
        res = res ^ arr[i];
    }
    int rightmost_setbit1 = (res) & (-res);
    for(int i = 0; i < sz; i++) {
        if((arr[i] & rightmost_setbit1)!= 0){
            n1 = n1 ^ (arr[i]);
        }
        res2 = res ^ n1;
    }
    int rightmost_setbit2 = res2 & (-res2);
    for(int i = 0; i < sz; i++) {
        if((arr[i] & rightmost_setbit2)!= 0){
            n2 = n2 ^ (arr[i]);
        }
        n3 = res2 ^ n2;
    }
    printf("3 unique numbers: n1 = %d, n2 = %d, n3 = %d\n", n1, n2, n3);
}

int main()
{
    int arr[] = {9, 14, 9, 14,11, 11, 4, 12, 3};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    find_non_duplicate(arr, sz);
    
    return 0;
}