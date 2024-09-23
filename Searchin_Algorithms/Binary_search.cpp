#include <iostream>
using namespace std;


int BinarySearch(int arr[], int n, int target) {
    int low = 0, high = n-1, mid = 0;

    while(low < high) {
        mid = (low + high) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] > target) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 6;

    int res = BinarySearch(arr, n, target);
    if(arr[res] == target) {
        cout << "Target found at index " << res;
    }
    else {
        cout << "Target was not found. The right position would be at index " << res;
    }
    return 0;
}