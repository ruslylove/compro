#include <stdio.h>

int add(int a, int b)      { return a + b; }
int multiply(int a, int b) { return a * b; }

void perform_operation(int x, int y, int (*op_func)(int, int)) {
    printf("Operation result: %d\n", op_func(x, y));
}

int main() {
    int (*calculator_ptr)(int, int);

    calculator_ptr = add;
    printf("Calling via pointer (add):      %d\n", calculator_ptr(5, 3));

    calculator_ptr = multiply;
    printf("Calling via pointer (multiply): %d\n", calculator_ptr(5, 3));

    printf("\nUsing perform_operation:\n");
    perform_operation(10, 2, add);
    perform_operation(10, 2, multiply);
    return 0;
}
