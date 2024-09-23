#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

//Get return value from a thread (pthread_join)

void* roll_dice(void* args){
    int val = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = val;
    return (void*)result;
}

int main()
{
    int* res;
    srand(time(NULL));
    pthread_t th;
    
    pthread_create(&th, NULL, &roll_dice, NULL);
    pthread_join(th, (void**)&res);
    
    printf("\nResult = %d", *res);
    
    free(res);
    return 0;
}
