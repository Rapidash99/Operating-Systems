#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handler (int sig) {
	signal(SIGINT, handler);
	printf("User, i am notifying you\n");
	fflush(stdout);
}

int main (void) {
	signal(SIGINT, handler);
	while (1)
		sleep (3);
	return 0;
}