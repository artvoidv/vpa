#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define func(a) (1.0/(((a)*(a))+1.0))

int
main(void)
{
    double max, min, tmin, start, end, j;
    int n;
    printf("Enter start value, end value and jump value: ");
    n = scanf("%lf %lf %lf", &start, &end, &j);
    if (n != 3) {
        fputs("input err\n", stderr);
        return 1;
    }
    if (!(j > 1e-9 && end > start)) {
        fputs("bad values\n", stderr);
        return 1;
    }
    double i = start;
    double tmp;
    int isxatzero = ((start<0 && end>0) && (fabs(start) - (int)(fabs(start)/j) * j <= 1e-9));
    puts("Y = 1/((X^2)+1)");
    printf("%15c | %-15c\n", 'x', 'y');
    for(; i <= end; i+=j) {
        tmp = func(i);
        printf("%15.5lf | %-15.5lf\n", i, tmp);
    }
    if (isxatzero) {
        max = 1;
        min = func(start);
        tmin = func(i-j);
        if (tmin < min) {
            min = tmin;
        }
    } else {
        if (end <= 1.0) {
            min = func(start);
            max = func(i-j);
        } else if (start >= 1.0) {
            max = func(start);
            min = func(i-j);
        } else {
            max = func(fabs(start) - (int)(fabs(start)/j) * j);
            min = func(start);
            tmin = func(i-j);
            if (tmin < min) {
                min = tmin;
            }
        }
    }
    printf("max: %10.5lf\nmin: %10.5lf\n", max, min);
    return 0;
}
