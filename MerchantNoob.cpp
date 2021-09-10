#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <thread>
using namespace std;

#define MAX_SIZE 10
#define PRODUCER_COUNT 4
#define CONSUMER_COUNT 4
sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;
class Queue
{
    long long qfront;
    long long qrear;
    long long queue_array[MAX_SIZE];

public:
    Queue() : qfront(-1), qrear(-1) {}
    bool isEmpty()
    {
        return qfront == qrear && qfront == -1;
    }
    bool IsFull()
    {
        return (qrear + 1) % MAX_SIZE == qfront ? true : false;
    }
    void enque(long long x)
    {
        if (IsFull())
        {
            cout << "Queue Full!!\n";
            return;
        }
        else if (isEmpty())
        {
            qfront = qrear = 0;
        }
        else
        {
            qrear = (qrear + 1) % MAX_SIZE;
        }
        queue_array[qrear] = x;
    }
    void deque_element()
    {
        if (isEmpty())
        {
            cout << "Error!! Cannot deque empty queue!!\n";
        }
        else if (qfront == qrear)
        {
            qfront = qrear = -1;
        }
        else
        {
            qfront = (qfront + 1) % MAX_SIZE;
        }
    }
    long long get_front()
    {
        if (isEmpty())
        {
            cout << "Error!! Cannot return front from empty queue!\n";
            return -1;
        }
        else
        {
            return queue_array[qfront];
        }
    }
    void printStatus()
    {
        if (isEmpty())
        {
            cout << "Buffer Holds Nothing\n";
        }
        else
        {
            cout << "Current State of the buffer :  ";
            for (int i = 0; i < MAX_SIZE; i++)
            {
                cout << queue_array[i] << " ";
            }
            cout << "\n\n";
        }
    }
};
Queue buffer;
int count = 0;
int x = 0;
void *producer(void *args)
{
    while (1)
    {
        // Produce
        // int x = rand() % 100;
        x++;
        sleep(1);
        if (buffer.IsFull())
        {
            cout << "Waiting for a consumer to consume\n";
        }
        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer.enque(x);
        cout << "producer produced : " << x << endl;
        buffer.printStatus();
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        int y;
        if (buffer.isEmpty())
        {
            cout << "Waiting for producer to produce\n";
        }
        // Remove from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        y = buffer.get_front();
        buffer.deque_element();
        cout << "Consumer Consumed " << y << endl;
        buffer.printStatus();
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);

        // Consume
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_t th[PRODUCER_COUNT + CONSUMER_COUNT];
    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);
    int i;
    for (i = 0; i < PRODUCER_COUNT; i++)
    {
        if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }
    for (int j = 0; j < CONSUMER_COUNT; j++)
    {

        if (pthread_create(&th[j + i], NULL, &consumer, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < PRODUCER_COUNT + CONSUMER_COUNT; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}