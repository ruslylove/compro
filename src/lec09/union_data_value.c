#include <stdio.h>
#include <string.h>

union DataValue {
    int   i;
    float f;
    char  str[20];
};

int main() {
    union DataValue data;

    data.i = 10;
    printf("Data as int:    %d\n", data.i);

    data.f = 220.5;
    printf("Data as float:  %.1f\n", data.f);

    strcpy(data.str, "Hello");
    printf("Data as string: %s\n", data.str);
    return 0;
}
