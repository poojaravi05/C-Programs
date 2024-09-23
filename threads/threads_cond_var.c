#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel; //condition variable

void* fuel_filling(void* arg){
    for(int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("\nFilled fuel = %d", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel); //signals only 1 thread
        pthread_cond_broadcast(&condFuel); //signals all the waiting thread
        sleep(1);
    }
}

void* car(void* arg){
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40){
        printf("\nNo fuel...waiting");
        pthread_cond_wait(&condFuel, &mutexFuel); //waits until it gets signal
        //Equivalent to: pthread_mutex_unlock(&mutexFuel); and then wait for a signal on cond and then lock it again.
    }
    fuel -= 40;
    printf("\nGot fuel. Now left = %d", fuel);
    
    pthread_mutex_unlock(&mutexFuel);
}

int main(){
    int i;
    pthread_t th[2];
    
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    
    for(i = 0; i < 2; i++){
        if(i == 1) {
           pthread_create(&th[i], NULL, &fuel_filling, NULL);
        }
        else {
           pthread_create(&th[i], NULL, &car, NULL);
        }
    }
    for(i = 0; i < 2; i++){
        pthread_join(th[i], NULL);
    }
    
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
   
    return 0;
}
