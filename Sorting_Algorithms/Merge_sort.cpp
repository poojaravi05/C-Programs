#include <iostream>
using namespace std;

int arr[] = {2, 4, 1, 7, 5, 3};
int n = sizeof(arr)/sizeof(arr[0]);
int b[10];

void Merge(int low, int mid, int high) {
    int l1, l2, i;
    for(l1 = low, l2 = mid+1, i = low; l1 <= mid && l2 <= high; i++) {
        if(arr[l1] <= arr[l2]) {
            b[i] = arr[l1++];
        }
        else {
            b[i] = arr[l2++];
        }
    }
    while(l1 <= mid) {
        b[i++] = arr[l1++];
    }
    while(l2 <= high) {
        b[i++] = arr[l2++];
    }
    for(i = low; i <= high; i++) {
        arr[i] = b[i];
    }
}

void Sort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low+high)/2;
        Sort(low, mid);
        Sort(mid+1, high);
        Merge(low, mid, high);
    }
    else {
        return;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Sort(0, n-1);
    cout << "Sorted Array: \n";
    printArray(arr, n);

    return 0;
}