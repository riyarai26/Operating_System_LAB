// Dining Philosopher Problem

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num)
{
    int id = *(int *)num;
    printf("Philosopher %d is thinking\n", id);
    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id + 1) % N]);
    printf("Philosopher %d is eating\n", id);
    sleep(1);
    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % N]);
    printf("Philosopher %d finished eating\n", id);
}

int main()
{
    pthread_t tid[N];
    int i, a[N];

    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < N; i++)
    {
        a[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &a[i]);
    }

    for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}