#include <stdio.h>
#include <stdlib.h>

int main(){
    int number;
    int *array;
    printf ("Enter number of elements below: ");
    scanf ("%d", &number);
    array = (int *) malloc(sizeof(number));
    for(int i = 0; i < number; i++) array[i] = i;
    for(int i = 0; i < number; i++) printf("%d ", array[i]);
    free (array);
    return 0;
}