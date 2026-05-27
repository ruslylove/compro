#include <stdio.h>
#include <string.h>

int main() {
    char names[4][20] = {"Alice", "Bob", "Charlie", "David"};

    for (int i = 0; i < 4; i++)
        printf("Name %d: %s\n", i + 1, names[i]);

    strcpy(names[1], "Robert");
    printf("\nAfter modification: %s\n", names[1]);
    return 0;
}
