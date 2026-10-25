#include <stdio.h>
#include <unistd.h>
#include <math.h>

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
    double start, end, jump, min, max;
    int n, j;
    int isxmeetzero = 0;
    n = j = 0;
    printf("Введите начальное, конечное значение и шаг\n");
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        puts("Недостаточно значений\n");
        return 1; 
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение\n");
        return 1;
    }
    if (start + end == 0 && (iseq(end,(double)((int)end)) && ((int)end)%((int)jump)==0)) {
        isxmeetzero = 1;
    }
    puts("Y = 1/((X^2)+1)\n");
    printf("%20s | %s\n", "X", "Y");
    for (double i = start; i < end; i+=jump,j++) {
        double tmp = 1/((i*i)+1);
        printf("%20.10lf | %20.10lf\n", i, tmp);
        if (j == 0) {
            max = min = tmp;
        } else {
            if (!isxmeetzero) {
                if (tmp>max) {
                    max=tmp;
                }
                if (tmp<min) {
                    min=tmp;
                }
            } else {
                if (tmp<min) {
                    min=tmp;
                }
            }
        }
    }
    printf("максимальное: %19.10lf\nминимальное: %20.10lf\nколичество операций: %d\n", isxmeetzero ? 2 : max, min, j);
    return 0;
}
