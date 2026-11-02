#include <stdio.h>

double
rectanglePerimeter(double a, double b)
{
    return 2.0*(a+b);    
}

int
main(void)
{
    double a, b;
    printf("Введите стороны прямоугольника через пробел\n");
    int n = scanf("%lf %lf", &a, &b);
    if (n != 2) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    printf("Периметр прямоугольника со сторонами %.6lf и %.6lf равен %.6lf\n", a, b, rectanglePerimeter(a,b));
    return 0;
}
