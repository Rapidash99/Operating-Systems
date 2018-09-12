#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int main() {
    char command[10];
    while (TRUE) {
        printf("> ");
        scanf("%s", command);
        system(command);
    }
    return 0;
}