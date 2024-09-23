#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n-2; i++) {
        int flag = 0;
        for(int j = 0; j < n-i-1; j++) {
            //j < n-i-1 = to neglect the sorted element at the rightmost side
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = 1; // to indicate that swapping happened
            }
        }
        if(flag == 0) { // if there was no swap in prev itr, it means the arr is sorted.
            break;
        }
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
    BubbleSort(arr, n);
    cout << "Sorted Array: \n";
    printArray(arr, n);

    return 0;
}