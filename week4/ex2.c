#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int j;
    for (j = 0; j < 3; j++) {
        fork();
        sleep(5);
    }
    return 0;
}
