#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int k;
    int l = -1;
    int m;
    for (i = n; i > 0; i--) {
        for (k = i - 1; k >= 0; k--){
            printf(" ");
        }
        for (m = l + 2; m > 0; m--){
            printf("*");
        }
        l += 2;
        printf("\n");
    }
    return 0;
}
