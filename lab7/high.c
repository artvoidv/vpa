#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void
printmatrix(int *m, int r, int c)
{
    printf("     ");
    for (int i = 0; i < c; i++) {
        printf(" %2s%1d ", "#", i+1);
    }
    putchar('\n');
    for (int i = 0; i < r; i++) {
        printf(" %2s%1d ", "#", i+1);
        for (int j = 0; j < c; j++) {
            printf(" %3d ", m[i * c + j]);
        }
        putchar('\n');
    }
}

int
main()
{
    int matrix[ROWS][COLS] = {0};
    srand((unsigned)time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = -50 + rand() % 101;
        }
    }
    puts("Изначальная матрица:");
    printmatrix(&matrix[0][0], ROWS, COLS);
    printf("Введите строку для удаления: ");
    int row;
    int n = scanf("%d", &row);
    if (n != 1) {
        return 1;
    }
    row--;
    if (row+1>ROWS) {
        puts("нет такой строки");
        return 1;
    }
    for (int i = row; i < ROWS; i++) {
        if (i==ROWS) break;
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = matrix[i+1][j];
        }
    }
    puts("Матрица после удаления строки:");
    printmatrix(&matrix[0][0], ROWS-1, COLS);
    return 0;
}
