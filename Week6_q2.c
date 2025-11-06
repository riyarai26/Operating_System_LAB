// Producer–Consumer Problem

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5
int buffer[SIZE], in=0, out=0;
sem_t mutex, full, empty;

void* producer(void* arg) {
    int item=1;
    while(1) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Producer produced %d\n", item++);
        in = (in+1)%SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void* consumer(void* arg) {
    while(1) {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("Consumer consumed %d\n", buffer[out]);
        out = (out+1)%SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}

int main() {
    pthread_t p, c;
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,SIZE);
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    return 0;
}
