#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int i;
    for (i = 0; i < 20; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = i;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)arg), buffer[in], in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < 20; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n", *((int *)arg), item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main() {
    pthread_t producers[5], consumers[5];
    int producer_num[5] = {1, 2, 3, 4, 5};
    int consumer_num[5] = {1, 2, 3, 4, 5};
    int i;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < 5; i++) {
        pthread_create(&producers[i], NULL, producer, (void *)&producer_num[i]);
        pthread_create(&consumers[i], NULL, consumer, (void *)&consumer_num[i]);
    }
    for (i = 0; i < 5; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

