//Find the smallest missing positive integer

#include <stdio.h>
#include <stdlib.h>

int find_missing(int A[], int N) {
    //int* present = (int*)calloc(sizeof(int), N+1);
    int present[100] = {0};

    for(int i = 0; i < N; i++) {
        if(A[i] > 0 && A[i] <= N) {
            present[A[i]] = 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(present[i] == 0) {
            //free(present);
            return i;
        }
    }
    //free(present);
    return N+1;
}

int main() {
    int A[] = {0, 2, 3, 4, 1, 6};
    int N = sizeof(A) / sizeof(A[0]);

    int res = find_missing(A, N);
    printf("Missing smallest integer is %d\n", res);

    return 0;
}