#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

#define NUM_THREADS 4
#define INCREMENTS 100

atomic_int counter;

int atomic_inc_manual(atomic_int *ptr) {
    int old_val, new_val;

    do {
        old_val = atomic_load(ptr);
        new_val = old_val + 1;
    } while (!atomic_compare_exchange_strong(ptr, &old_val, new_val));

    return new_val;
}

void* worker(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        atomic_inc_manual(&counter);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    atomic_init(&counter, 0);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", atomic_load(&counter));

    return 0;
}
