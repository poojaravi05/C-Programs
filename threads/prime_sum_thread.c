#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

//add all the numbers in prime array.
//idea: half of the array is given to th1, other half to th2.

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* args){
    int index = *(int*)args;
    int sum = 0;
    for(int j = 0; j < 5; j++){
        sum += prime[index + j];
    }
    *(int*)args = sum;
    return args;
}

/*
void* routine(void* args){
    int* index = (int*)args;
    int* sum = malloc(sizeof(int)); // Allocate memory for the result
    *sum = 0;
    for(int j = 0; j < 5; j++){
        *sum += prime[*index + j];
    }
    return sum;
}
*/

int main()
{
    pthread_t th[2];
    int i;
    
    for(i = 0; i < 2; i++){
        int* a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread\n");
            return 1;
        }
        printf("\nThread %d has started\n", i);
    }
    int globalSum = 0;
    for(i = 0; i < 2; i++){
        int* res;
        if (pthread_join(th[i], (void**)&res) != 0) {
            return 2;
        }
        globalSum += *res; //to accumulate sums from 2 threads
        printf("\nThread %d has stopped\n", i);
        free(res);
    }
    printf("\nGlobal Sum = %d", globalSum);
        //no need to free a, since a is given to args and that is returning as res.
    return 0;
}
