#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number > 0) {
        printf("The number %d is positive.\n", number);
    }

    printf("End of program.\n");
    return 0;
}
