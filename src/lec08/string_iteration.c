#include <stdio.h>

int main(void) {
    char s[] = "abc";

    /* index style */
    for (int i = 0; s[i] != '\0'; i++) printf("%c", s[i]);
    printf("\n");

    /* pointer style */
    for (char *p = s; *p != '\0'; p++) printf("%c", *p);
    printf("\n");
    return 0;
}
