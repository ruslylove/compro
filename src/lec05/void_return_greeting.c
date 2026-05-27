#include <stdio.h>

void print_greeting(int times) {
    int i;
    for (i = 0; i < times; i++)
        printf("Hello! ");
    printf("\n");
}

int main() {
    print_greeting(3);
    return 0;
}
