#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <unistd.h>
#include <limits.h>

typedef struct {
    atomic_int locked;
} mutex_t;

void mutex_init(mutex_t *m)
{
    atomic_init(&m->locked, 0);
}

void mutex_lock(mutex_t *m)
{
    while (1)
    {
        int expected = 0;

        if (atomic_compare_exchange_weak(&m->locked, &expected, 1))
            return;

        syscall(SYS_futex, &m->locked, FUTEX_WAIT, 1, NULL, NULL, 0);
    }
}

void mutex_unlock(mutex_t *m)
{
    atomic_store(&m->locked, 0);
    syscall(SYS_futex, &m->locked, FUTEX_WAKE, 1, NULL, NULL, 0);
}

typedef struct {
    atomic_int seq;
} cond_t;

void cond_init(cond_t *c)
{
    atomic_init(&c->seq, 0);
}

void cond_wait(cond_t *c, mutex_t *m)
{
    int old_seq = atomic_load(&c->seq);

    mutex_unlock(m);

    syscall(SYS_futex, &c->seq, FUTEX_WAIT, old_seq, NULL, NULL, 0);

    mutex_lock(m);
}

void cond_signal(cond_t *c)
{
    atomic_fetch_add(&c->seq, 1);
    syscall(SYS_futex, &c->seq, FUTEX_WAKE, 1, NULL, NULL, 0);
}

void cond_broadcast(cond_t *c)
{
    atomic_fetch_add(&c->seq, 1);
    syscall(SYS_futex, &c->seq, FUTEX_WAKE, INT_MAX, NULL, NULL, 0);
}

mutex_t lock;
cond_t cond;

int ready = 0;

void* worker(void *arg)
{
    mutex_lock(&lock);

    while (!ready)
    {
        printf("Thread waiting...\n");
        cond_wait(&cond, &lock);
    }

    printf("Thread awakened!\n");

    mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    mutex_init(&lock);
    cond_init(&cond);

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    sleep(2);

    mutex_lock(&lock);

    ready = 1;

    printf("Main thread broadcasting...\n");

    cond_broadcast(&cond);

    mutex_unlock(&lock);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
