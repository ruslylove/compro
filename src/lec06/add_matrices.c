#include <stdio.h>
#define ROWS 2
#define COLS 3

void addMatrices(int a[][COLS], int b[][COLS], int result[][COLS], int num_rows) {
    for (int r = 0; r < num_rows; r++)
        for (int c = 0; c < COLS; c++)
            result[r][c] = a[r][c] + b[r][c];
}

int main() {
    int matrixA[ROWS][COLS] = {{1,  2,  3},  {4,  5,  6}};
    int matrixB[ROWS][COLS] = {{10, 11, 12}, {13, 14, 15}};
    int sum[ROWS][COLS];

    addMatrices(matrixA, matrixB, sum, ROWS);

    printf("Resultant Matrix:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            printf("%d ", sum[r][c]);
        printf("\n");
    }
    return 0;
}
