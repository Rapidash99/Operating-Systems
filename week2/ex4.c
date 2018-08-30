#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first;
    int second;
    scanf("%d", &first);
    scanf("%d", &second);
    swap(&first, &second);
    printf("%d %d", first, second);
    return 0;
}

void swap(int *first, int *second) {
    int temp = *second;
    *second = *first;
    *first = temp;
}
