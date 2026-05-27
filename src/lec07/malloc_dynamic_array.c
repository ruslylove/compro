#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_elements = 5;
    int *dyn_array = NULL;
    int i;

    dyn_array = (int *)malloc(num_elements * sizeof(int));
    if (dyn_array == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    printf("Enter %d integers:\n", num_elements);
    for (i = 0; i < num_elements; i++)
        scanf("%d", &dyn_array[i]);

    printf("You entered:\n");
    for (i = 0; i < num_elements; i++)
        printf("%d ", dyn_array[i]);
    printf("\n");

    free(dyn_array);
    dyn_array = NULL;
    return 0;
}
