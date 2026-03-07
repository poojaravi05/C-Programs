/*
Includes the C11 atomic operations library.
Provides lock-free atomic operations.
*/
#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>   // for usleep()

typedef struct {
    atomic_flag lock; // 0 = unlocked, 1 = locked
} mutex_t;

/* Initialize the mutex */
void mutex_init(mutex_t* m) {
    atomic_flag_clear(&m->lock);
}

/* Acquire the mutex */
void mutex_lock(mutex_t* m) {

    while (atomic_flag_test_and_set(&m->lock)) {
        // Instead of spinning continuously, sleep
        usleep(100);   // sleep 100 microseconds
    }

}

/* Release the mutex */
void mutex_unlock(mutex_t* m) {
    atomic_flag_clear(&m->lock);
}

#define THREAD_NUM 4
#define INCREMENTS 10

mutex_t lock;
int counter = 0;

void* incrementer(void* args) {

    int id = *(int*)args;

    for(int i = 0; i < INCREMENTS; i++) {

        mutex_lock(&lock);

        counter++;

        printf("%s: Thread %d incremented counter to %d in loop %d\n",
               __func__, id, counter, i);

        mutex_unlock(&lock);
    }

    return NULL;
}

int main() {

    mutex_init(&lock);

    pthread_t th[THREAD_NUM];
    int th_id[THREAD_NUM];

    for(int i = 0; i < THREAD_NUM; i++) {
        th_id[i] = i + 1;
        pthread_create(&th[i], NULL, incrementer, &th_id[i]);
    }

    for(int i = 0; i < THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    printf("Final counter = %d\n", counter);

    return 0;
}
