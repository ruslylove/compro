#include <stdio.h>

int global_var = 100;

void some_function(int param) {
    int function_local = 20;
    printf("Inside function: param=%d, function_local=%d, global_var=%d\n",
           param, function_local, global_var);

    if (param > 5) {
        int block_local = 30;
        printf("Inside if block: block_local=%d\n", block_local);
    }
}

int main() {
    int main_local = 10;
    printf("Inside main: main_local=%d, global_var=%d\n", main_local, global_var);
    some_function(main_local);
    return 0;
}
