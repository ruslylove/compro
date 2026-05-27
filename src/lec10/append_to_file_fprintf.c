#include <stdio.h>

int main() {
    FILE *fp    = NULL;
    char  name[] = "David";
    int   score  = 85;

    fp = fopen("output.txt", "a");
    if (fp == NULL) {
        perror("Error opening file for appending");
        return 1;
    }

    fprintf(fp, "Name: %s\n",  name);
    fprintf(fp, "Score: %d\n", score);
    fprintf(fp, "-----------\n");

    printf("Data appended to output.txt\n");
    fclose(fp);
    return 0;
}
