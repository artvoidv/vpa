#include <stdio.h>

#define vswap(a, b) vswap_(&a, &b)
void
vswap_(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

int
main(void)
{
    double a, b;
    int n;
    printf("Введите 2 числа: ");
    n = scanf("%lf %lf", &a, &b);
    if (n != 2) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    printf("до vswap():    a: %lf b: %lf\n", a, b);
    vswap(a, b);
    printf("после vswap(): a: %lf b: %lf\n", a, b);
    return 0;
}
