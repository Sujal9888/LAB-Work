#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

int value = 1;
sem_t mutex;

void *sleepA(void *u)
{
    printf("From A\n");

    sem_wait(&mutex);
    value += 5;
    printf("A: I am going to sleep for %d seconds.\n", value);

    sleep(value);

    printf("A: Slept for %d seconds.\n", value);
    sem_post(&mutex);

    return NULL;
}

void *sleepB(void *u)
{
    printf("From B\n");

    sem_wait(&mutex);
    value += 2;
    printf("B: I am going to sleep for %d seconds.\n", value);

    sleep(value);

    printf("B: Slept for %d seconds.\n", value);
    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    time_t t;
    time(&t);

    sem_init(&mutex, 0, 1);

    printf("DATE: \n %s", ctime(&t));
    printf("Initial value: %d\n", value);

    pthread_create(&tid1, NULL, &sleepA, NULL);
    pthread_create(&tid2, NULL, &sleepB, NULL);

    printf("Main Thread\n");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final Global Variable Value: %d\n", value);

    sem_destroy(&mutex);

    return 0;
}
