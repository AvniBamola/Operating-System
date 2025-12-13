#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#define ITEMS 5

int buffer =-1;      // single - slot buffer
sem_t empty;
sem_t full;
pthread_mutex_t mutex;         // protects access to buffer

void *producer(void *arg)
{
    int i;
    for(i=1;i<=ITEMS;i++)
    {
        sem_wait(&empty);     //wait for an empty slot
        pthread_mutex_lock(&mutex);    // enter critical section

        buffer =i;    // produce item
        printf("Producer produces: %d\n",buffer);

        pthread_mutex_unlock(&mutex);   //leave critical section
        sem_post(&full);            // signal that buffer is full;

        usleep(1000000);      // small sleep so output interleaves nicely
    }
    return NULL;
}

void *consumer(void *arg)
{
    int i;
    for(i=1;i<=ITEMS;i++)
    {
        sem_wait(&full);     //wait for filled slots
        pthread_mutex_lock(&mutex); //enter critical section
        int item=buffer;       //consume item;
        buffer=-1;
        printf("Consumer consumed: %d\n",item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        usleep(1000000);   //small sleep
    }
    return NULL;
}

int main()
{
    pthread_t p,c;
    sem_init(&empty,0,1);     // one empty slot initially
    sem_init(&full,0,1);
    pthread_mutex_init(&mutex,NULL);    // no filled slots initially

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("Done\n");
    return 0;
}