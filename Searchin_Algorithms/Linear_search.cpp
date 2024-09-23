#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 2, 4, 3, 8, 5, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = LinearSearch(arr, n, 2);
    if(res == -1) {
        cout << "Target not found";
    }
    else {
        cout << "Target found at index " << res;
    }

    return 0;
}