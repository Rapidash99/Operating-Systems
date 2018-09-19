#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* printHello(void *args) {
    printf("Hello from thread %d\n", (int) pthread_self());
    return 0;
}

int main() {
    pthread_t thread;
    int rc;
    int rc_addr;

    int i;
    for (i = 0; i < 10; i++) {
        rc = pthread_create(&thread, NULL, printHello, (void*)i);
        if (rc) {
            printf("\nERROR: return code from pthread_create is %d\n", rc);
            exit(1);
        }
        printf("Thread was created by main\n");

        rc = pthread_join(thread, (void**)&rc_addr);
        if (rc) {
            printf("\nERROR: return code from pthread_join is %d\n", rc);
            exit(1);
        }
    }

    printf("joined with address %d\n", rc_addr);

    return 0;
}
