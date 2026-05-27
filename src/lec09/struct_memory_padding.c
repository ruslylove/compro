#include <stdio.h>

typedef struct {
    char c1;   /* 1 byte  */
    int  i;    /* 4 bytes */
    char c2;   /* 1 byte  */
} ExampleStruct;

int main() {
    printf("sizeof(char)         = %zu\n", sizeof(char));
    printf("sizeof(int)          = %zu\n", sizeof(int));
    printf("sizeof(ExampleStruct)= %zu\n", sizeof(ExampleStruct));
    return 0;
}
