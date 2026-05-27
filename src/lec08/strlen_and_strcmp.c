#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "apply";

    printf("Length of \"%s\" is %zu\n", str1, strlen(str1));

    int cmp = strcmp(str1, str2);
    if      (cmp == 0) printf("\"%s\" and \"%s\" are equal.\n",        str1, str2);
    else if (cmp  < 0) printf("\"%s\" comes before \"%s\".\n",         str1, str2);
    else               printf("\"%s\" comes after \"%s\".\n",          str1, str2);
    return 0;
}
