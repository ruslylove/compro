#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int          data;
    struct Node *next;
} Node;

int main(void) {
    Node *head       = malloc(sizeof(Node));
    head->data       = 1;
    head->next       = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;

    for (Node *cur = head; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->data);
    printf("NULL\n");

    free(head->next);
    free(head);
    return 0;
}
