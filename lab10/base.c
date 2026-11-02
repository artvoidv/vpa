#include <stdio.h>

void
square(int *a)
{
    *a = (*a) * (*a);
}

int
main(void)
{
    int a;
    printf("Введите число: ");
    int n = scanf("%d", &a);
    if (n != 1) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    int o = a;
    square(&a);
    printf("%d^2 = %d\n", o, a);
    return 0;
}
