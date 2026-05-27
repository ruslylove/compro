#include <stdio.h>
#define ROWS 8
#define COLS 8

int main() {
    int image[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            printf(image[r][c] ? "* " : "  ");
        printf("\n");
    }
    return 0;
}
