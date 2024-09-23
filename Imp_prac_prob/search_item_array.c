//In the given sorted array, if the target is found, return the index it.
//If not, return the index where it is supposed to be.

#include <stdio.h>

int binarySearch(int arr[], int sz, int target) {
    int l = 0, r = sz-1;
    int mid = 0;

    while(l <= r) {
        int mid = l + (r-l) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[mid] > target) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
    int arr[] = {1, 3, 4, 10, 12, 17, 28};
    int sz = sizeof(arr)/sizeof(arr[0]);

    int target = 2;

    int res = binarySearch(arr, sz, target);

    if(arr[res] == target) {
        printf("Element found at index %d", res);
    }
    else {
        printf("Element not found. It should be inserted at index %d", res);
    }

    return 0;
}