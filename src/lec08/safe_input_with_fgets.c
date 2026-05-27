#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 20

int main() {
    char full_name[BUFFER_SIZE];

    printf("Enter your full name: ");
    if (fgets(full_name, BUFFER_SIZE, stdin) != NULL) {
        full_name[strcspn(full_name, "\n")] = 0;
        printf("Welcome, %s!\n", full_name);
    }
    return 0;
}
