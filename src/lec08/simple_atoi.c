#include <stdio.h>

int simple_atoi(const char str[]) {
    int result = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            result = result * 10 + (str[i] - '0');
        else
            break;
        i++;
    }
    return result;
}

int main() {
    char num_str[] = "1998";
    int  value     = simple_atoi(num_str);
    printf("String \"%s\" as integer: %d\n", num_str, value);
    printf("Calculation: %d * 2 = %d\n", value, value * 2);
    return 0;
}
