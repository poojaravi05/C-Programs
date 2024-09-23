#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

//pass arguments to threads

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* args){
    int index = *(int*)args;
    printf("%d ", prime[index]);
    free(args);
}

int main()
{
    pthread_t th[10];
    int i;
    
    for(i = 0; i < 10; i++){
        //if we don't dynamically allocate memory, there can be repetitions. Since threads share memory,
        //and creation happens and it takes memory reference, the desired output will not come.
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread\n");
            return 1;
        }
        printf("\nThread %d has started\n", i);
    }
    for(i = 0; i < 10; i++){
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("\nThread %d has stopped\n", i);
    }
    
    return 0;
}
