#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello";
    char src[]    = ", World!";

    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("Concatenated: %s\n", dest);

    char new_dest[10];
    char long_src[] = "This is a very long string";
    strncpy(new_dest, long_src, sizeof(new_dest) - 1);
    new_dest[sizeof(new_dest) - 1] = '\0';
    printf("Copied: %s\n", new_dest);
    return 0;
}
