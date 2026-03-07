#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <unistd.h>

typedef struct {
    atomic_int count;
}sema_t;

void semaphore_init(sema_t* s, int val) {
    atomic_store(&s->count, val);
}

void semaphore_wait(sema_t* s) {
    while(1) {
        int val = atomic_load(&s->count);
        if(val > 0) {
            if(atomic_compare_exchange_strong(&s->count, &val, val-1)) {
                break;
            }
        }
        else {
            syscall(SYS_futex, &s->count, FUTEX_WAIT, 0, NULL, NULL, 0);
        }
    }
}

void semaphore_post(sema_t* s) {
    atomic_fetch_add(&s->count, 1);
    syscall(SYS_futex, &s->count, FUTEX_WAKE, 1, NULL, NULL, 0);
}

#define THREAD_NUM 4
#define INCREMENTS 5
#define COUNT_VAL 1 // only 1 thread at a time

sema_t lock;
int counter = 0;

void* incrementer(void* args) {
    int id = *(int*)args;

    for(int i = 0; i < INCREMENTS; i++) {
        semaphore_wait(&lock);
        counter++;
        printf("%s: Thread %d incremented counter to %d in loop %d\n", __func__, id, counter, i);
        semaphore_post(&lock);
    }
    return NULL;
}

int main() {
    semaphore_init(&lock, COUNT_VAL);

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