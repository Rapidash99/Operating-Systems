#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


pid_t pid_child;

void kill_it(int sign) {
    kill(pid_child, SIGKILL);
}

int main() {
    signal(SIGALRM, (void (*)(int))kill_it);
    pid_child = fork();
    if (pid_child == -1) exit(1);

    if (pid_child == 0){
        while(1) {
            printf("I'm alive\n");
            sleep(1);
        }
    }

    else {
        sleep(10);
        kill_it(getpid());
    }

    return 0;
}