#include <stdio.h>
#include <stdlib.h>

int main() {
    int len = 6;
    int* array = malloc(len);
    int i;
    for (i = 0; i < len; i++){
        array[i] = rand();
    }
    bubble_sort(array, len);

    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int array[], int len) {
    int i;
    int k;
    for (i = 0; i < len; i++) {
        for (k = 1; k < len; k++) {
            if (array[k] < array[k - 1]) {
                swap(&array[k], &array[k - 1]);
            }
        }
    }
}
