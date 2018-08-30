#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    int i;
    double d;
    float f;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("%d %d %d\n", sizeof(i), sizeof(f), sizeof(d));
    printf("%d %f %lf\n", i, f, d);
    return 0;
}
