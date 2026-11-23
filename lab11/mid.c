#include <stdio.h>
#include <stdlib.h>

void
printarr(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
}

int
multiplyArray(int *a, int n, int f)
{
    int s, sn;
    for (int i = 0; i < n; i++) {
        s = a[i];
        sn = s * f;
        if (s < 0) { 
            if (sn > 0) {
                return 1; 
            }
        } else { 
            if (sn < 0) {
                return 1; 
            }
        }
        a[i] = sn;
    }
    return 0;
}

int
main(void)
{
    size_t s;
    int *arr;
    int n, f;
    printf("Введите размер массива: ");
    n = scanf("%zd", &s);
    if (n != 1) {
        fputs("Ошибка ввода\n", stderr);
        return 1;
    }
    arr = malloc(sizeof(int) * s);
    if (!arr) {
        fputs("malloc failed\n", stderr);
        return 1;
    }
    printf("Введите %zd эллементов массива\n", s);
    for (size_t i = 0; i<s; ++i) {
        n = scanf("%d", &(arr[i]));
        if (n != 1) {
            fputs("Ошибка ввода\n", stderr);
            return 1;
        }
    }
    printf("Введите на какое число умножать: ");
    n = scanf("%d", &f);
    if (n != 1) {
        fputs("Ошибка ввода\n", stderr);
        return 1;
    }
    puts("\nИзначанльый массив: ");
    if (multiplyArray(arr, s, f)) {
        fputs("Переполнение int\n", stderr);
        return 1;
    }
    printarr(arr, s);
    puts("\nМассив после умножения: ");
    printarr(arr, s);
    putchar('\n');
    return 0;
}
