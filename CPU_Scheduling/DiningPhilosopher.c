#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define N 5   // 5 philosophers
sem_t forks[5];

void *philosopher(void *num)
{
    int id=*(int *)num;

    while(1)
    {
        printf("Philosopher %d is thinking \n",id);
        sleep(1);
        sem_wait(&forks[id]);     // pick left fork
        sem_wait(&forks[(id+1)%N]);  //pick right fork

        printf("Philosopher %d is eating\n",id);
        sleep(1);

        sem_post(&forks[id]);      //release left fork
        sem_post(&forks[(id+1)%N]);     //release right fork

    }
}
int main()
{
    pthread_t ph[5];
    int ids[5];
    int i;
    for(int i=0;i<5;i++)
    {
        sem_init(&forks[i],0,1);
    }
    for(int i=0;i<5;i++)
    {
        ids[i]=i;
        pthread_create(&ph[i],NULL,philosopher,&ids[i]);
    }
    for(i=0;i<5;i++)
    {
        pthread_join(ph[i],NULL);
    }
    return 0;
}