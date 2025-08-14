#include <stdio.h>

#define ROWS 8
#define COLS 8

void print_image(int image[][COLS], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            if (image[r][c] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    // A 2D array representing the letter 'F'
    int transposed[ROWS][COLS], image[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Example: Transpose
    for (int r=0; r<ROWS; r++) {
        for (int c=0; c<COLS; c++) {
            transposed[c][r] = image[r][c];
        }
    }

    printf("Original Image:\n");
    print_image(image, ROWS);
    printf("\nTransposed Image:\n");
    print_image(transposed, ROWS);
}