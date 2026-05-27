#include <stdio.h>

int main() {
    int  code_num = 79;  // ASCII for 'O'
    char letter   = 'n'; // ASCII 110

    printf("As decimals:    code_num = %d, letter = %d\n",  code_num, (int)letter);
    printf("As characters:  code_num = %c, letter = %c\n",  code_num, letter);
    printf("As hex:         code_num = %x, letter = %x\n",  code_num, (int)letter);
    return 0;
}
