#include <stdio.h>

#define ROWS 5
#define COLS 3

int
main()
{
    int matrix[ROWS][COLS] = {0};
    for (int i = 0; i<ROWS; i++) {
        printf("Введите 3 эллемента матрицы строки %d через пробел\n", i+1);
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }
    unsigned char count = 0;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLS; j++) {
            if (matrix[i][j] < 0) {
                count++;
            }
        }
    }
    printf("Количество отрицательных элементов: %d\n", (int)count);
    return 0;
}
