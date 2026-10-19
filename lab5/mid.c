#include <stdio.h>
#include <limits.h>

int
main()
{
    int start = 10, end = 44, jump = 5;
    double min = INT_MAX, max = 0;
    double result;
    printf("y=1/(x^2-1)\n");
    printf("%9c | %c\n", 'x', 'y');
    for (int i = start; i < end; i+=jump) {
        result = 1.0/((double)(i*i)-1.0);
        if (result >= max) {
            max = result;
        }
        if (result <= min) {
            min = result;
        }
        printf("%9d | %.8lf\n", i, result);
    }
    printf("min: %.8lf\nmax: %.8lf\n", min, max);
    return 0;
}
