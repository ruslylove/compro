#include <stdio.h>

int main() {
    int   score   = 95;
    float average = 88.7;
    char  grade   = 'A';

    printf("Score: %d\n",   score);
    printf("Average: %f\n", average);
    printf("Grade: %c\n",   grade);
    printf("Result - Score: %d, Grade: %c\n", score, grade);
    return 0;
}
