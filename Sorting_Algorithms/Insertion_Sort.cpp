#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int val = arr[i];
        int hole = i;
        while(hole > 0 && arr[hole-1] > val) {
            arr[hole] = arr[hole-1];
            hole = hole-1;
        }
        arr[hole] = val;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 4, 1, 7, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, n);
    cout << "Sorted Array: \n";
    printArray(arr, n);

    return 0;
}