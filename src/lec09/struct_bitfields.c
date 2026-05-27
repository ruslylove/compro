// Lecture 9: Struct Bit-Fields
#include <stdio.h>
#include <stdint.h>

// A date packed into 16 bits
typedef struct {
    uint16_t day   : 5; // 5 bits for day (0-31)
    uint16_t month : 4; // 4 bits for month (0-15)
    uint16_t year  : 7; // 7 bits for year (0-127, relative to a base year)
} PackedDate;

int main() {
    PackedDate today;
    today.day = 18;
    today.month = 9;
    today.year = 25; // Representing 2025

    printf("Size of PackedDate: %zu bytes\n", sizeof(PackedDate));
    printf("Date: %u/%u/%u\n", today.month, today.day, today.year + 2000);

    return 0;
}
