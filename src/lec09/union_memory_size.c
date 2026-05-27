#include <stdio.h>

union ExampleUnion {
    int    i;
    double d;
    char   c;
};

int main() {
    printf("sizeof(int)          = %zu\n", sizeof(int));
    printf("sizeof(double)       = %zu\n", sizeof(double));
    printf("sizeof(char)         = %zu\n", sizeof(char));
    printf("sizeof(ExampleUnion) = %zu\n", sizeof(union ExampleUnion));
    return 0;
}
