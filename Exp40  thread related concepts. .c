#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Hello from thread!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, thread_func, NULL)) {
        printf("Error in creating thread 1.\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, thread_func, NULL)) {
        printf("Error in creating thread 2.\n");
        return 1;
    }

    if (pthread_equal(thread1, thread2)) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are not equal.\n");
    }

    if (pthread_join(thread1, NULL)) {
        printf("Error in joining thread 1.\n");
        return 1;
    }
    if (pthread_join(thread2, NULL)) {
        printf("Error in joining thread 2.\n");
        return 1;
    }

    printf("Threads successfully joined.\n");

    return 0;
}

