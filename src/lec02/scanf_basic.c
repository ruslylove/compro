#include <stdio.h>

int main() {
    int   quantity = 0;
    float price    = 0.0;

    printf("Initial values: quantity = %d, price = %f\n", quantity, price);
    printf("Enter quantity (integer) and price (float), separated by space: ");
    scanf("%d %f", &quantity, &price);
    printf("Values after input: quantity = %d, price = %f\n", quantity, price);
    return 0;
}
