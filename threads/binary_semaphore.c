#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 1

// Binary semaphore is used to make sure if some resource was utilized.

sem_t semFuel;
pthread_mutex_t mutexFuel;

int *fuel;

void* routine(void* args) {
    // doesn't have to wait on anything, because the fuel is allocated before creating/executing the routine.
    *fuel += 50;
    printf("Current value is %d\n", *fuel);
    sem_post(&semFuel);
}

int main(int argc, char *argv[]) {
    // We want 1 thread should use this memory and after using it, the main thread should be deallocated.
    pthread_t th[THREAD_NUM];
    fuel = malloc(sizeof(int));
    *fuel = 50;
    pthread_mutex_init(&mutexFuel, NULL);
    sem_init(&semFuel, 0, 0);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }
    sem_wait(&semFuel); // sem is 0, so it stops right here until the routine finishes its execution and calls post.
    // now we know for certain that the thread did something.

    printf("Deallocating fuel\n");
    free(fuel);

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}