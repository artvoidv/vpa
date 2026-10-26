#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int
main()
{
    int matrix[ROWS][COLS] = {0};
    int n;
    int sum = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            n = 1 + rand() % 20;
            if (n % 3 == 0) {
                sum += n;
            }
            matrix[i][j] = n;
        }
    }
    printf("Сумма элементов кратных трем: %d\n", sum);
    return 0;
}
