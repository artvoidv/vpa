#include <stdio.h>

int
main()
{
    double input;
    double result;
    printf("Введите x: ");
    int n = scanf("%lf", &input);
    if (n != 1) {
        puts("Ошибка ввода");
        return 1;
    }    
    result = input * input;
    printf("Квадрат числа %.10lf равен %.10lf\n", input, result);
    return 0;
}
