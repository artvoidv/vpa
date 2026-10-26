#include <stdio.h>

#define ROWS 5
#define COLS 3

int
main()
{
    int matrix[ROWS][COLS] = {0};
    int n;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLS; j++) {
            printf("Введите эллемент матрицы %d,%d\n", i+1,j+1);
            n = scanf("%d", &matrix[i][j]);
            if (n != 1) {
                return 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLS; j++) {
            if (matrix[i][j] < 0) {
                sum += matrix[i][j];
            }
        }
    }
    printf("Сумма отрицательных элементов: %d\n", sum);
    return 0;
}
