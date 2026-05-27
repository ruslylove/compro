// Lecture 9: Self-Referential Structs: a Peek at Linked Lists
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {        // tag is required so the pointer can refer back
    int          data;
    struct Node *next;       // pointer to the next node, or NULL at the end
} Node;

int main(void) {
    Node *head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;

    for (Node *cur = head; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->data);
    printf("NULL\n");

    free(head->next);
    free(head);
    return 0;
}
