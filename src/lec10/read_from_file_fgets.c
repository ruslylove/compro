#include <stdio.h>
#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp = NULL;
    char  line_buffer[MAX_LINE_LENGTH];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("File contents:\n");
    while (fgets(line_buffer, MAX_LINE_LENGTH, fp) != NULL)
        printf("%s", line_buffer);

    fclose(fp);
    return 0;
}
