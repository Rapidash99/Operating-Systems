#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1023];
    scanf("%s", str);
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    return 0;
}
