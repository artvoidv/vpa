#include <stdio.h>

void
printarr(int* a, int n) 
{
    for (int i = 0; i < ((n/2)+(n%2 ? 1 : 0)); i++) {
        printf("%d ", a[i]);
        a++;
    }
}

int
main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printarr(arr, 7);
    return 0;
}
