#include <stdio.h>

#define arrSIZE 20

int
main()
{
    double arr[arrSIZE];
    double bufn = 0.0;
    double sum;
    int c;
    unsigned char status = 0;
    double frac = 0.1;
    for (int i = 0; i < arrSIZE; i++) {
        printf("Введите число #%d: ", i+1);
        while((c = getchar()) != '\n') {
            if (c == EOF) {
                putchar('\n');
                return 0;
            }
            if (c == '-' && status < 1) {
                status++;
                continue;
            }
            if (c == '.') {
                status += 2;
            }
            if (c >= '0' && c <= '9') {
                if (status > 1) {
                    bufn = bufn + (c - '0') * frac;
                    frac *= 0.1;
                } else {
                    bufn = (bufn * 10.0) + (c - '0');
                }
            }
        }
        arr[i] = bufn * ((status % 2) ? -1 : 1);
        if (i%2) {
            sum += arr[i];
        }
        bufn = 0.0; frac = 0.1; status = 0;
    }
    printf("Сумма: %lf\n", sum);
    return 0;
}
