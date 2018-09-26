#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int main() {
    int states[2];
    pid_t pid_child;
    char one[] = "Some text";
    char other_one[64];

    pipe(states);

    if (pid_child == 0) close(0);

    if (fork() != 0) {
        close(states[0]);
        write(states[1], one, (strlen(one) + 1));
        close(states[1]);
    }

    else {
        close(states[1]);
        printf("The other one string is: %s", other_one);
        close(states[0]);
    }

    return 0;
}
