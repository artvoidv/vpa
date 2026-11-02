#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define EPSILON 1E-9

int
iseq(double a, double b)
{
    if (fabs(a-b) < EPSILON) return 1;
    return 0;
}

int
main()
{
    double start, end, jump, min, max;
    int n;
    n = 0;
    puts("Введите начальное, конечное значение и шаг через пробел");
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        puts("Недостаточно значений");
        return 1; 
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение");
        return 1;
    }
    puts("Y = 1/((X^2)+1)");
    printf("%20s | %s\n", "X", "Y");
    for (double i = start; i <= end; i+=jump) {
        double tmp = 1/((i*i)+1);
        printf("%20.10lf | %20.10lf\n", i, tmp);
    }

    double last = start + (floor(end/jump) * jump);
    if (start < 0 && last > 0) {
        max = 1.0;
        min = 1/((start*start)+1);
        double min2 = 1/((last*last)+1);
        if (min > min2) {
            min = min2;
        }
    }
    if (last < 0) {
        min = 1/((start*start)+1);
        max = 1/((last*last)+1);
    }
    printf("максимальное: %19.10lf\nминимальное: %20.10lf\n\n", max, min);
    printf("last : %lf\n", last);
    return 0;
}
