#include <stdio.h>

int
main()
{
    double input, squared, cubed;
    printf("Введите x: ");
    int n = scanf("%lf", &input);
    if (n != 1) {
        puts("Ошибка ввода");
        return 1;
    }
    squared = input * input;
    cubed = input * input * input;

    printf("Квадрат числа %.10lf равен %.10lf\nКуб числа %.10lf равен %.10lf\n", input, squared, input, cubed);
    return 0;
}
