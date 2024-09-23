#include <iostream>
using namespace std;

void SelectionSort(int A[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_Indx = i;
        for(int j = i+1; j < n; j++) {
            if(A[j] < A[min_Indx]) {
                min_Indx = j; // Min value index
            }
        }
        if(min_Indx != i) {
            swap(A[min_Indx], A[i]); //swap subsequent min value in the ith position
        }
    }
}

void printArray(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 7, 4, 1, 5, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, sz);
    cout << "Sorted Array: \n";
    printArray(arr, sz);

    return 0;
}