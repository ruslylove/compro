#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr_int = NULL;

    ptr_int = (int *)malloc(sizeof(int));
    if (ptr_int == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr_int = 123;
    printf("Value stored in dynamic memory: %d\n", *ptr_int);

    free(ptr_int);
    ptr_int = NULL;
    return 0;
}
