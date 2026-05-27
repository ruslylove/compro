#include <stdio.h>
#include <string.h>

int main() {
    char sentence[]       = "C is a powerful, general-purpose language.";
    const char delimiters[] = " ,.-";

    printf("Original: \"%s\"\nTokens:\n", sentence);

    char *token = strtok(sentence, delimiters);
    while (token != NULL) {
        printf("  - %s\n", token);
        token = strtok(NULL, delimiters);
    }
    return 0;
}
