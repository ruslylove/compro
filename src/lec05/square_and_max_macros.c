#include <stdio.h>

#define LIMIT    10
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int num = 5;
    int sq         = SQUARE(num);
    int another_sq = SQUARE(num + 1);

    int x = 3, y = 7;
    int maximum = MAX(x, y);

    printf("Square of %d is %d\n",     num,     sq);
    printf("Square of %d is %d\n",     num + 1, another_sq);
    printf("Max of %d and %d is %d\n", x,       y, maximum);
    return 0;
}
