// Find the element that appears once and other elements appear 3 times
// Find the element that is appearing only once in the array

#include <stdio.h>

int findSingle(int arr[], int n) {
    int ones = 0, twos = 0, commonBits;

    for (int i = 0; i < n; i++) {
        // Update twos for the bits that are present in arr[i] and ones
        twos |= (ones & arr[i]);

        // Update ones for the bits that are present in arr[i] and not in ones
        ones ^= arr[i];

        // The common bits present in ones and twos indicate bits that have appeared thrice
        commonBits = ~(ones & twos);

        // Remove common bits from ones and twos
        ones &= commonBits;
        twos &= commonBits;
    }

    return ones;
}

int main() {
    int arr[] = {4, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int singleElement = findSingle(arr, n);
    printf("The element appearing only once is: %d\n", singleElement);
    return 0;
}
