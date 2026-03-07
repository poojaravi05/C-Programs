#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <limits.h>

typedef struct {
    atomic_int count;
    int threshold;
    atomic_int cycle;
} barrier_t;

barrier_t barrier;

void barrier_init(barrier_t *b, int threshold) {
    atomic_init(&b->count, 0);
    atomic_init(&b->cycle, 0);
    b->threshold = threshold;
}

void barrier_wait(barrier_t *b) {

    int current_cycle = atomic_load(&b->cycle);

    if (atomic_fetch_add(&b->count, 1) == b->threshold - 1) {

        atomic_store(&b->count, 0);
        atomic_fetch_add(&b->cycle, 1);

        syscall(SYS_futex, &b->cycle, FUTEX_WAKE, INT_MAX, NULL, NULL, 0);

    } else {

        while (atomic_load(&b->cycle) == current_cycle) {
            syscall(SYS_futex, &b->cycle, FUTEX_WAIT, current_cycle, NULL, NULL, 0);
        }

    }
}

void* worker(void* arg) {

    int id = *(int*)arg;

    printf("Thread %d before barrier\n", id);

    sleep(rand() % 3);

    barrier_wait(&barrier);

    printf("Thread %d after barrier\n", id);

    return NULL;
}

int main() {

    int n = 4;
    pthread_t threads[n];
    int ids[n];

    barrier_init(&barrier, n);

    for (int i = 0; i < n; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
