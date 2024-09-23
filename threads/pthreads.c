#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 2;

// In the context of using the POSIX threads (pthreads) library in C, the thread functions are defined to return a void* and take a void* as an argument to provide flexibility and generality.

void *thread_func1(void *args)
{
    int *val = (int *)args;
    
    printf("\n%s: Enter. Thread id: %d\n", __func__, *val);
    sleep(3);
    a++;
    printf("The value of a with id %d = %d", *val, a);
    printf("\n%s: Exit. Thread id: %d\n", __func__, *val);
}

void *thread_func2(void *args)
{
    int *val = (int *)args;
    int n;
    
    printf("\n%s: Enter. Thread id: %d\n", __func__, *val);
    printf("\nPlease enter a number: ");
    scanf("%d", &n);
    printf("\nThe entered number is : %d\n", n);
    printf("The value of a with id %d = %d", *val, a);
    printf("\n%s: Exit. Thread id: %d\n", __func__, *val);
}

int main()
{
    pthread_t th1, th2;
    int th1_id = 1, th2_id = 2;
    
    pthread_create(&th1, NULL, &thread_func1, (void *)&th1_id);
    pthread_create(&th2, NULL, &thread_func2, (void *)&th2_id);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 2;

void *thread_func1(void* val) {
    int id = *(int *)val;
    printf("\n%s: Enter. Thread id: %d\n", __func__, id);
    sleep(3);
    a++;
    printf("The value of a with id %d = %d", id, a);
    printf("\n%s: Exit. Thread id: %d\n", __func__, id);
    return NULL;
}

void *thread_func2(void *val) {
    int id = *(int *)val;
    int n;

    printf("\n%s: Enter. Thread id: %d\n", __func__, id);
    printf("\nPlease enter a number: ");
    scanf("%d", &n);
    printf("\nThe entered number is : %d\n", n);
    printf("The value of a with id %d = %d", id, a);
    printf("\n%s: Exit. Thread id: %d\n", __func__, id);
    return NULL;
}

int main() {
    pthread_t th1, th2;
    int th1_id = 1, th2_id = 2;

    pthread_create(&th1, NULL, &thread_func1, (void *)&th1_id);
    pthread_create(&th2, NULL, &thread_func2, (void *)&th2_id);

    //pthread_create(&th1, NULL, thread_func1, &th1_id);
    //pthread_create(&th2, NULL, thread_func2, &th2_id);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}

*/