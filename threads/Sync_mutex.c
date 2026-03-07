#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <unistd.h>

typedef struct{
    atomic_int state; // 0 = unlocked, 1 = locked
}mutex_t;

//sets state value to 0
void mutex_init(mutex_t* m) {
    atomic_store(&m->state, 0);
    //atomic_init(&m->state, 0);
}

void mutex_lock(mutex_t* m) {
    int expected = 0;
    /*
    compare m->state with expected
    If equal: m->state = 1, return success -> while(!1) = while(0) -> lock acquired
    Otherwise: operation fails -> while(!0) = while(1) -> syscall (wait until lock is released)
    */
    while(!atomic_compare_exchange_strong(&m->state, &expected, 1)) {
        expected = 0;
        syscall(SYS_futex, &m->state, FUTEX_WAIT, 1, NULL, NULL, 0);
        /*
        Parameter meaning:
        Parameter	    Meaning
        &m->state	    address to monitor
        FUTEX_WAIT	    sleep operation
        1	            expected value to go to sleep
        NULL	        no timeout
        NULL	        unused
        0	            flags
        */
    }
}

void mutex_unlock(mutex_t* m) {
    atomic_store(&m->state, 0);
    syscall(SYS_futex, &m->state, FUTEX_WAKE, 1, NULL, NULL, 0);
    /*
    Parameter meaning:
    Parameter	    Meaning
    &m->state	    address to monitor
    FUTEX_WAKE	    wake operation
    1	            wake 1 thread
    NULL	        no timeout
    NULL	        unused
    0	            flags
    */
}

#define THREAD_NUM 4
#define INCREMENTS 5

mutex_t lock;
int counter = 0;

void* incrementer(void* args) {
    int id = *(int*)args;

    for(int i = 0; i < INCREMENTS; i++) {
        mutex_lock(&lock);
        counter++;
        printf("%s: Thread %d incremented counter to %d in loop %d\n", __func__, id, counter, i);
        mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    mutex_init(&lock);

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