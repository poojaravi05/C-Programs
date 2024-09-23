#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 0;
pthread_mutex_t mutex;

void* increment(void *args){
    for(int i = 0; i < 2; i++){
        pthread_mutex_lock(&mutex);
        //int *id = (int *)args;
        a++;
        printf("\n%s From Thread, a = %d", __func__, a);
        pthread_mutex_unlock(&mutex);
    }
}

void* decrement(void *args){
    for(int i = 0; i < 2; i++){
        pthread_mutex_lock(&mutex);
        int *id = (int *)args;
        a--;
        printf("\n%s From Thread %d, a = %d", __func__, *id, a);
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t th[4];
    
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < 4; i++){
        if (pthread_create(&th[i], NULL, &increment, NULL) != 0) {
            perror("Failed to create thread\n");
            return 1;
        }
        printf("\nThread %d has started\n", i);
    }
    for(int i = 0; i < 4; i++){
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("\nThread %d has stopped\n", i);
    }
    //if pthread_create and pthread_join are called in same for loop,
    //it doesn't make sense for multi-threaded programming, as 1 one thread starts on after the other thread finishes.
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}