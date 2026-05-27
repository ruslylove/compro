#include <stdio.h>

int main() {
    int  score = 75;
    char grade;

    if      (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else                  grade = 'F';

    printf("Score: %d, Grade: %c\n", score, grade);
    return 0;
}
