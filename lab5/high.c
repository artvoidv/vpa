#include <stdio.h>
#include <math.h>
#include "high.h"

int
iseq(double a, double b)
{
    double EPSILON = 1E-9;
    if (fabs(a-b) < EPSILON) return 1;
    return 0;
}

int
main()
{
    double start, end, jump;
    double S, ans;
    S = ans = 0.0;
    int n, j;
    n = j = 0;
    printf("Введите пределы интегрирования и шаг\n");
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        puts("Недостаточно значений\n");
        return 1; 
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение\n");
        return 1;
    }
    for (double i = start+jump; !(i > end-jump); i+=jump) {
        S += f(i);
    }
    ans = jump * (((f(start)+f(end))/2) + S);
    printf("%lf\n", ans);
    return 0; 
}
