#include <stdio.h>

int main() {
    int grid[2][3] = { {10, 20, 30}, {40, 50, 60} };

    grid[1][1] = 99;

    printf("Grid Contents:\n");
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++)
            printf("%d ", grid[r][c]);
        printf("\n");
    }
    return 0;
}
