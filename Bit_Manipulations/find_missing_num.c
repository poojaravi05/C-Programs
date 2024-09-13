#include <stdio.h>

int find_missing_number(int *arr, int sz)
{
    int actual_sz = sz + 1;
    int res = 0;
    
    for (int i = 0 ; i < sz; i++)
    {
        res = res ^ (arr[i] ^ (i + 1));
    }
    
    res = res ^ actual_sz;
    
    return res;
}

int main()
{
    int arr[] = {2, 1, 5, 4};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    int missing_number = find_missing_number(arr, sz);
    printf("The missing number in the array is: %d\n", missing_number);
    return 0;
}