#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 20; i++) {
        printf("Checking %d\n", i);
        if (i % 7 == 0) {
            printf("Found number divisible by 7: %d\n", i);
            break;
        }
        printf("... still searching ...\n");
    }
    printf("Loop finished or exited via break.\n");
    return 0;
}
