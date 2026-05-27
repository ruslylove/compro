#include <stdio.h>

int main() {
    int values[5] = {10, 20, 30, 40, 50};

    printf("The third element is: %d\n", values[2]);

    values[3] = 44;

    printf("All values: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", values[i]);
    printf("\n");
    return 0;
}
