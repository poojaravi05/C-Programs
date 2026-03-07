#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <unistd.h>
#include <errno.h>

typedef struct {
    atomic_int count;
} sema_t;

/* Initialize semaphore */
void sema_init(sema_t *s, int value)
{
    atomic_init(&s->count, value);
}

/* Wait (P operation) */
void sema_wait(sema_t *s)
{
    while (1)
    {
        int val = atomic_load(&s->count);

        /* Resource available */
        if (val > 0)
        {
            if (atomic_compare_exchange_weak(&s->count, &val, val - 1))
                return;
        }
        else
        {
            /* Sleep while count == 0 */
            syscall(SYS_futex, &s->count, FUTEX_WAIT, 0, NULL, NULL, 0);
        }
    }
}

/* Post (V operation) */
void sema_post(sema_t *s)
{
    atomic_fetch_add(&s->count, 1);

    /* Wake one waiting thread */
    syscall(SYS_futex, &s->count, FUTEX_WAKE, 1, NULL, NULL, 0);
}

#define THREADS 5
#define LOOPS 3
#define SEM_VALUE 2

sema_t sem;
atomic_int counter = 0;

void* worker(void *arg)
{
    int id = *(int*)arg;

    for(int i = 0; i < LOOPS; i++)
    {
        sema_wait(&sem);

        int val = atomic_fetch_add(&counter, 1) + 1;

        printf("Thread %d entered critical section, counter=%d\n", id, val);

        sleep(1);

        printf("Thread %d leaving\n", id);

        sema_post(&sem);
    }

    return NULL;
}

int main()
{
    pthread_t threads[THREADS];
    int ids[THREADS];

    sema_init(&sem, SEM_VALUE);

    for(int i = 0; i < THREADS; i++)
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for(int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Final counter = %d\n", atomic_load(&counter));

    return 0;
}
