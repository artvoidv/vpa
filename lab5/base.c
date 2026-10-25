#include <stdio.h>
#include <unistd.h>

int
main()
{
    double start, end, jump;
    int n;
    puts("Y = (X-2)^2\nВведите начальное значение, конечное и шаг через пробел");
    n = scanf("%lf %lf %lf", &start, &end, &jump);
    if (n != 3) {
        return 1;
    }
    if (start>end || !(jump>0)) {
        puts("Введено неверное значение");
        return 1;
    }
    printf("%20s | %s\n", "X", "Y");
    for (double i = start; i <= end; i+=jump) {
        printf("%20.5lf | %lf\n", i , (double)(i-2.0)*(i-2.0));
    }
}
