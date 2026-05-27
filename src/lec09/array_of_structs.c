#include <stdio.h>

typedef struct {
    char title[100];
    char author[50];
    int  year;
} Book;

int main() {
    Book library[3] = {
        {"The C Programming Language", "K&R",           1978},
        {"Pride and Prejudice",        "Jane Austen",    1813},
        {.title="Dune", .author="Frank Herbert", .year=1965}
    };

    for (int i = 0; i < 3; i++)
        printf("Book %d: %s by %s (%d)\n",
               i + 1, library[i].title, library[i].author, library[i].year);
    return 0;
}
