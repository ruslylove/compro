// Lecture 6: Passing 2D Arrays to Functions
#include <stdio.h>
#define ROWS 2
#define COLS 3

// Function must know the number of columns
void print2DArray(int arr[][COLS], int num_rows) {
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    print2DArray(matrix, ROWS);
    return 0;
}
