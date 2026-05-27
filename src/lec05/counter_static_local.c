#include <stdio.h>

void counter_function() {
    int auto_count    = 0;
    static int static_count = 0;

    auto_count++;
    static_count++;
    printf("auto_count = %d, static_count = %d\n", auto_count, static_count);
}

int main() {
    counter_function(); /* auto=1, static=1 */
    counter_function(); /* auto=1, static=2 */
    counter_function(); /* auto=1, static=3 */
    return 0;
}
