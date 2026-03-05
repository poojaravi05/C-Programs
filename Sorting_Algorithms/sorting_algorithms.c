#include <stdio.h>
#include <stdbool.h>

/*
The sorting happens from right side
The highest element in each search is bubbled towards right side
Compares 2 adjacent elements
*/
int* bubble_sort(int* arr, int sz) {
    bool swapped;
    for(int i = 0; i < sz; i++) {
        swapped = false;
        for(int j = 0; j < sz-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    printf("Buuble sort: ");
    return arr;
}

/*
Assume 1st element is sorted and start from 2nd element.
Sorts all left elements to i
*/
int* insertion_sort(int* arr, int sz) {
    for(int i = 1; i < sz; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Insertion sort: ");
    return arr;
}

/*
At each iteration, finds the min element
Swaps the min element with the ith element
*/
int* selection_sort(int* arr, int sz) {
    for(int i = 0; i < sz; i++) {
        int min = i;
        for(int j = i+1; j < sz; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
    printf("Selection sort: ");
    return arr;
}

/*
Divide the array into halves until single separate element
Then merge elements in order recursively.
*/
void merge(int* arr, int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    //copy data to temporary array
    for(i = 0; i < n1; i++) {
        L[i] = arr[low+i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = arr[mid+1+j];
    }

    //merge the temp array to actual array
    i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the remaining elements from L or R
    while(i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

int* merge_sort(int* arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    return arr;
}

/*
Keep the last element as pivot
check if arr[j] < pivot and swap ith element with arr[j]
move pivot element to it's position(after smaller partition)
*/
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }  
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int* quick_sort(int* arr, int low, int high) {
    if(low < high) {
        int part_index = partition(arr, low, high);

        quick_sort(arr, low, part_index - 1);
        quick_sort(arr, part_index + 1, high);
    }
    return arr;
}

void print_array(int* arr, int sz) {
    for(int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 3, 4, 2, 5};
    //int sz = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, 5);

    //bubble_sort(arr, 5);
    //print_array(arr, 5);

    //insertion_sort(arr, 5);
    //print_array(arr, 5);

    //selection_sort(arr, 5);
    //print_array(arr, 5);

    //merge_sort(arr, 0, 4);
    //print_array(arr, 5);

    quick_sort(arr, 0, 4);
    print_array(arr, 5);

    return 0;
}