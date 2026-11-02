#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BOUND (100+1)
#define STARTVALUE -100

int
binsearch(int *c, int n, int s)
{
    int l = 0;
    int h = n-1;
    while (l <= h) {
        int m = l + (h-l)/2;
        if (c[m] == s) {
            return m;
        }
        if (c[m] > s) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

int*
genarray(int n)
{
    int* c = malloc(n * sizeof(int));
    int v;
    for (int i = 0; i < n; i++) {
        v = STARTVALUE + (i*BOUND) + (rand()%BOUND);
        c[i] = v;
    }
    return c;
}

void
printarray(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
}

int
main(void)
{
    srand((unsigned)(time(NULL) ^ getpid()));
    int size, search;
    printf("Введите размер: ");
    int n = scanf("%d", &size);
    if (n != 1) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    int* arr = genarray(size);
    printarray(arr, size);
    putchar('\n');

    printf("Введите число для поиска: ");
    n = scanf("%d", &search);
    if (n != 1) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    if (binsearch(arr, size, search) != -1) {
        printf("%d finded in array\n", search);
    } else {
        printf("%d not found in arr\n", search);
    }
    free(arr);
    return 0;
}
