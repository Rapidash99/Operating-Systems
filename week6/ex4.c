#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handler(int sig) {
    switch (sig) {
        case SIGKILL:
            signal(SIGKILL, handler);
            printf("got SIGKILL\n");
            fflush(stdout);
            break;

        case SIGSTOP:
            signal(SIGSTOP, handler);
            printf("got SIGSTOP\n");
            fflush(stdout);
            break;

        case SIGUSR1:
            signal(SIGUSR1, handler);
            printf("got SIGUSR1\n");
            fflush(stdout);
            break;

        case SIGINT:
            signal(SIGINT, handler);
            printf("got SIGINT\n");
            fflush(stdout);
            break;
    }
}

int main (void) {
    printf("My pid is: %d\n", getpid());

    if(signal(SIGKILL, handler) == SIG_IGN)
        signal(SIGKILL,SIG_IGN);

    else if(signal(SIGSTOP, handler) == SIG_IGN)
        signal(SIGSTOP,SIG_IGN);

    else if(signal(SIGUSR1, handler) == SIG_IGN)
        signal(SIGUSR1,SIG_IGN);

    else if(signal(SIGINT, handler) == SIG_IGN)
        signal(SIGINT,SIG_IGN);

    while (1)
        sleep (10);

    return 0;
}