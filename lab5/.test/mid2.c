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
    int n, j;
    int isxmeetzero = 0;
    n = j = 0;
#ifndef test
    puts("Введите начальное, конечное значение и шаг через пробел");
#endif
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        puts("Недостаточно значений");
        return 1; 
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение");
        return 1;
    }
    double k = round(-start / jump);
    double xatk = start + k * jump;
    if (k >= 0 && xatk <= end && fabs(xatk) < EPSILON) {
        isxmeetzero = 1;
    }
#ifndef test
    puts("Y = 1/((X^2)+1)");
    printf("%20s | %s\n", "X", "Y");
#endif
#ifdef test
    struct timespec timer_s, timer_e;
    clock_gettime(CLOCK_MONOTONIC, &timer_s);
#endif
    for (double i = start; i <= end; i+=jump,j++) {
        double tmp = 1/((i*i)+1);
#ifndef test
        printf("%20.10lf | %20.10lf\n", i, tmp);
#endif
        if (j == 0) {
            max = min = tmp;
        } else {
            if (!isxmeetzero) {
                if (tmp>max) {
                    max=tmp;
                }
            }
        }
    }
    double tmpi = start + (jump * (j-1));
    double tmp = 1/((tmpi*tmpi)+1);
    if (tmp<min) {
        min=tmp; 
    }
#ifdef test
    clock_gettime(CLOCK_MONOTONIC, &timer_e);
    double timer_f = (timer_e.tv_sec-timer_s.tv_sec) + (timer_e.tv_nsec-timer_s.tv_nsec)*1e-9;
    printf("%.6lf\n", timer_f);
#endif
#ifndef test
    printf("максимальное: %19.10lf\nминимальное: %20.10lf\nколичество операций: %d\n", isxmeetzero ? 1.0 : max, min, j);
#endif
    return 0;
}
