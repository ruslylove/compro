#include <stdio.h>

int main() {
    FILE *fp    = NULL;
    char  name[] = "Charlie";
    int   score  = 92;

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(fp, "Student Record\n");
    fprintf(fp, "Name: %s\n",  name);
    fprintf(fp, "Score: %d\n", score);
    fprintf(fp, "-----------\n");

    printf("Data written to output.txt\n");
    fclose(fp);
    return 0;
}
