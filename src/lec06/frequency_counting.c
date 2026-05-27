#include <stdio.h>
#define MAX_VALUE 100

int main() {
    int data[]  = {4, 8, 4, 1, 1, 8, 9, 4, 5};
    int count   = sizeof(data) / sizeof(data[0]);
    int frequency[MAX_VALUE];

    for (int i = 0; i < MAX_VALUE; i++) frequency[i] = 0;

    for (int i = 0; i < count; i++) {
        int v = data[i];
        if (v >= 0 && v < MAX_VALUE)
            frequency[v]++;
    }

    printf("Element Frequencies:\n");
    for (int i = 0; i < MAX_VALUE; i++)
        if (frequency[i] > 0)
            printf("Value %d appeared %d time(s).\n", i, frequency[i]);
    return 0;
}
