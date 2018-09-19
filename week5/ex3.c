#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define N 10

int c = 0;
char buffer[N];
time_t begin;
int i = 0;

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;

void *producer(void *ptr) {

    while (1) {
        pthread_mutex_lock(&the_mutex);

        if (c == N) {
            pthread_cond_wait(&condp, &the_mutex);
        }

        buffer[c] = 'p';
        c++;
        time_t end = time(NULL);

        if ((double)(end - begin) > i*6) {
            printf("Execution time:%f\n", ((double)(end - begin)));
            i++;
        }

        if (c == 1) {
            pthread_cond_signal(&condc);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}

void *consumer(void *ptr) {
    while (1) {
        pthread_mutex_lock(&the_mutex);
        if (c == 0) {
            pthread_cond_wait(&condc, &the_mutex);
        }
        buffer[c] = 'c';
        c--;
        if (c == N - 1) {
            pthread_cond_signal(&condp);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}


int main(int argc, char const *argv[]) {
    begin = time(NULL);
    pthread_t prod, cons;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&cons, 0, consumer, 0);
    pthread_create(&prod, 0, producer, 0);
    pthread_join(prod, 0);
    pthread_join(cons, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);

    return 0;
}
