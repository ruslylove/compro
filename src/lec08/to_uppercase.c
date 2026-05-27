#include <stdio.h>
#include <ctype.h>

void to_uppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

int main() {
    char message[] = "hello world";
    printf("Original:  %s\n", message);
    to_uppercase(message);
    printf("Uppercase: %s\n", message);
    return 0;
}
