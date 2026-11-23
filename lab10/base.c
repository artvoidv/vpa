#include <stdio.h>

#define square(a) square_(&a)
void
square_(int *a)
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
    printf("переменная a до square(): %d\n", a);
    square(a);
    printf("переменная a после square(): %d\n", a);
    return 0;
}
