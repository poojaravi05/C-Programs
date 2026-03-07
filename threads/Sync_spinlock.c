/*
Includes the C11 atomic operations library.
This header provides types and functions for lock-free thread-safe operations.
*/
#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>

/*
atomic_flag:
Only supports test-and-set and clear
Guaranteed lock-free
Used specifically for spinlocks
*/
typedef struct {
    atomic_flag lock; // 0 = unlocked, 1 = locked
}spinlock_t;

/* Initialize the spinlock */
void spinlock_init(spinlock_t* s) {
    atomic_flag_clear(&s->lock); // Sets the atomic flag to false (0).
}

/* Acquire the spinlock */
/*
It performs two operations atomically:
Reads the old value
Sets the flag to TRUE (1)
CASE 1: LOCK IS FREE
lock = 0, Thread calls: atomic_flag_test_and_set(), Operation: returns 0, sets lock = 1, Then: while(0), Loop exits immediately.Thread now owns the lock.
CASE 2: LOCK ALREADY TAKEN
lock = 1, Thread calls: atomic_flag_test_and_set(), Operation: returns 1, lock stays 1, Then:, while(1), Loop continues., Thread repeatedly tries again: test_and_set
This continuous retrying is called spinning.
*/
void spinlock_lock(spinlock_t* s) {
    while(atomic_flag_test_and_set(&s->lock));
}

/* Release the spinlock */
void spinlock_unlock(spinlock_t* s) {
    atomic_flag_clear(&s->lock);
}

#define THREAD_NUM 4
#define INCREMENTS 10

spinlock_t lock;
int counter = 0;

void* incrementer(void* args) {
    int id = *(int*)args;

    for(int i = 0; i < INCREMENTS; i++) {
        spinlock_lock(&lock);
        counter++;
        printf("%s: Thread %d incremented counter to %d in loop %d\n", __func__, id, counter, i);
        spinlock_unlock(&lock);
    }
    return NULL;
}

int main() {
    spinlock_init(&lock);

    pthread_t th[THREAD_NUM];
    int th_id[THREAD_NUM];

    for(int i = 0; i < THREAD_NUM; i++) {
        th_id[i] = i+1;
        pthread_create(&th[i], NULL, incrementer, &th_id[i]);
    }

    for(int i = 0; i < THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    printf("Final counter = %d\n", counter);

    return 0;
}

/*
Full Execution Timeline for 2 threads
Initial: lock = 0
Thread A:
spinlock_lock
test_and_set → returns 0
lock = 1
enter critical section

Thread B:
spinlock_lock
test_and_set → returns 1
spin
spin
spin

Thread A:
spinlock_unlock
lock = 0

Thread B:
test_and_set → returns 0
lock = 1
enter critical section
*/