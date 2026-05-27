#include <stdio.h>

enum Day   { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
enum Color { RED = 1, GREEN = 2, BLUE = 4 };

int main() {
    enum Day today = WEDNESDAY;

    if (today == WEDNESDAY || today == TUESDAY)
        printf("It's a weekday.\n");
    else
        printf("It's the weekend or another weekday.\n");

    enum Color my_color = BLUE;
    printf("Color value: %d\n", my_color);
    return 0;
}
