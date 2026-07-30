#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS 2

sem_t mutex;

void *criticalSection(void *threadID)
{
    int id = *(int *)threadID;

    for (int i = 0; i < 5; ++i)
    {
        sem_wait(&mutex);

        printf("Thread %d is in the critical section.\n", id);
        usleep(1000000);

        sem_post(&mutex);
        usleep(500000);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS] = {0, 1};

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_create(&threads[i], NULL, criticalSection, (void *)&threadIDs[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}
