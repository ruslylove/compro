#include <stdio.h>

int main(void) {
    char *str_ptr = "Welcome";   /* points to read-only literal */
    char  str_arr[] = "Welcome"; /* modifiable copy on the stack */

    printf("Pointer version: %s\n", str_ptr);
    printf("Array version:   %s\n", str_arr);

    str_arr[0] = 'w';
    printf("Modified array:  %s\n", str_arr);

    /* *str_ptr = 'W'; */ /* UNDEFINED BEHAVIOR */
    return 0;
}
