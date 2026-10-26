#include <stdio.h>
#include <math.h>

int
main()
{
    double legs[2] = {0};
    double hypotenuse;
    
    for (int i = 0; i < 2; i++) {
        printf("Введите катет №%d: ", i+1);
        int n = scanf("%lf", &legs[i]);
        if (n != 1) {
            puts("Ошибка ввода");
            return 1;
        }
    }
   
    hypotenuse = sqrt(pow(legs[0], 2)+pow(legs[1], 2)); 
    printf("Гипотенуза треугольника: %.10lf\nПлощадь треугольника: %.10lf\nПериметр треугольника: %.10lf\n",
            hypotenuse,
            legs[0]*legs[1]/2.0,
            hypotenuse + legs[0] + legs[1]);
    return 0;
}
