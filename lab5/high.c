#include <stdio.h>
#include <math.h>
#include "high.h"

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
    double start, end, jump;
    double sum, ans;
    sum = ans = 0.0;
    int n, j;
    n = j = 0;
    puts("Введите пределы интегрирования и шаг через пробел");
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        puts("Недостаточно значений");
        return 1; 
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение");
        return 1;
    }
    for (double i = start+jump; !(i > end-jump); i+=jump) {
        sum += f(i);
    }
    ans = jump * (((f(start)+f(end))/2) + sum);
    printf("%lf\n", ans);
    return 0; 
}
