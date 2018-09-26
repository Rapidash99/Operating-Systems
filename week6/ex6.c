#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main() {
    int states[2];
    pid_t first_child, second_child;
    first_child = fork();

    if(first_child == 0){
        pid_t sc_pid = -1;
        close(states[1]);
        read(states[0], &sc_pid, sizeof(pid_t));
        close(states[0]);

        printf("2nd child prepared to die\n");
        kill(sc_pid, SIGKILL);
    }
    else {
        second_child = fork();

        if(second_child == 0){
            while(1) printf("2nd child is working for the benefit of Russia\n");
        }

        else {
            close(states[0]);
            write(states[1], &second_child, sizeof(pid_t));
            close(states[1]);
            waitpid(second_child, NULL, 0);
        }
    }
    return 0;
}