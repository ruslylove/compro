#include <stdio.h>
#define NUM_STUDENTS 10

int main() {
    float scores[NUM_STUDENTS];
    float sum = 0.0, average, max, min;
    int i;

    printf("Enter %d scores:\n", NUM_STUDENTS);
    for (i = 0; i < NUM_STUDENTS; i++) {
        scanf("%f", &scores[i]);
        sum += scores[i];
    }

    average = sum / NUM_STUDENTS;
    max = min = scores[0];
    for (i = 1; i < NUM_STUDENTS; i++) {
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    printf("Average: %.2f\n", average);
    printf("Max: %.2f, Min: %.2f\n", max, min);
    return 0;
}
