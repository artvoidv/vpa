#include <stdio.h>

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
        if (s < 0) { /* negative number */
            if (sn > 0) {
                return 1; /* int overflow */
            }
        } else { /* positive number */
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printarr(arr, 7);
    if (multiplyArray(arr, 7, 2)) {
        fputs("Переполнение int", stderr);
        return 1;
    }
    puts("\nМассив после умножения: ");
    printarr(arr, 7);
    putchar('\n');
    return 0;
}
