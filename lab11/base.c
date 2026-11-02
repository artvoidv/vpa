#include <stdio.h>

void
vswap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int
main(void)
{
    int a = 10;
    int b = -452;
    printf("Оригинальные числа: %d %d\n", a, b);
    vswap(&a, &b);
    printf("Оригинальные переменные после swap: %d %d\n", a, b);
    return 0;
}
