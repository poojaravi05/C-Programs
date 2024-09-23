#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 0;
pthread_mutex_t mutex;

void* increment(void *args){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutex);
        int *id = (int *)args;
        a++;
        printf("\n%s From Thread %d, a = %d", __func__, *id, a);
        pthread_mutex_unlock(&mutex);
    }
}

void* decrement(void *args){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutex);
        int *id = (int *)args;
        a--;
        printf("\n%s From Thread %d, a = %d", __func__, *id, a);
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t th1, th2;
    int th1_id = 1, th2_id = 2;
    
    pthread_mutex_init(&mutex, NULL);
    
    if (pthread_create(&th1, NULL, &increment, (void *)&th1_id) != 0) {
        return 1;
    }
    if (pthread_create(&th2, NULL, &decrement, (void *)&th2_id) != 0) {
        return 2;
    }
    
    if (pthread_join(th1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(th2, NULL) != 0) {
        return 4;
    }
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}