#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define PRODUCER_COUNT 4
#define CONSUMER_COUNT 4

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t semEmpty;
sem_t semFull;
pthread_mutex_t mutex;

void* producer(void* args) {
    int id = *(int*)args;
    
    while(1) {
        int item = rand() % 100;
        sleep(1);
        
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d produced %d at index %d\n", id, item, in);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&semFull);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* args) {
    int id = *(int*)args;
    
    while(1) {
        sem_wait(&semFull);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d consumed %d from index %d\n", id, item, out);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&semEmpty);
        pthread_mutex_unlock(&mutex);
        
        sleep(1);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    sem_init(&semEmpty, 0, BUFFER_SIZE);
    sem_init(&semFull, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t producer_th[PRODUCER_COUNT];
    pthread_t consumer_th[CONSUMER_COUNT];
    
    int prod_id[PRODUCER_COUNT];
    int cons_id[CONSUMER_COUNT];
    
    for(int i = 0; i < PRODUCER_COUNT; i++) {
        prod_id[i] = i+1;
        pthread_create(&producer_th[i], NULL, producer, &prod_id[i]);
    }
    
    for(int i = 0; i < CONSUMER_COUNT; i++) {
        cons_id[i] = i+1;
        pthread_create(&consumer_th[i], NULL, consumer, &cons_id[i]);
    }
    
    for(int i = 0; i < PRODUCER_COUNT; i++) {
        pthread_join(producer_th[i], NULL);
    }
    
    for(int i = 0; i < CONSUMER_COUNT; i++) {
        pthread_join(consumer_th[i], NULL);
    }
    
    return 0;
}

