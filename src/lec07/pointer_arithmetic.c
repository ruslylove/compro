#include <stdio.h>

int main() {
    int    numbers[] = {10, 20, 30, 40};
    char   letters[] = {'A', 'B', 'C', 'D'};
    double values[]  = {1.1, 2.2, 3.3, 4.4};

    int    *ptr_int    = numbers;
    char   *ptr_char   = letters;
    double *ptr_double = values;

    printf("Initial addresses:\n");
    printf("ptr_int    = %p\n", (void *)ptr_int);
    printf("ptr_char   = %p\n", (void *)ptr_char);
    printf("ptr_double = %p\n", (void *)ptr_double);

    ptr_int++;
    ptr_char++;
    ptr_double++;

    printf("\nAddresses after ptr++:\n");
    printf("ptr_int    = %p (value %d)\n",  (void *)ptr_int,    *ptr_int);
    printf("ptr_char   = %p (value %c)\n",  (void *)ptr_char,   *ptr_char);
    printf("ptr_double = %p (value %.1f)\n",(void *)ptr_double,  *ptr_double);
    return 0;
}
