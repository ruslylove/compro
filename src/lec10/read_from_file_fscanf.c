#include <stdio.h>

int main() {
    FILE *fp = NULL;
    char  name[50];
    int   score;

    fp = fopen("scores.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Reading scores:\n");
    while (fscanf(fp, "%s %d", name, &score) == 2)
        printf("Name: %s, Score: %d\n", name, score);

    fclose(fp);
    return 0;
}
