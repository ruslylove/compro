#include <stdio.h>

typedef struct { int id; float gpa; } Record;

int main(void) {
    Record  r = {101, 3.85f};
    Record *p = &r;

    printf("via value:   id=%d  gpa=%.2f\n", r.id,  r.gpa);
    printf("via pointer: id=%d  gpa=%.2f\n", p->id, p->gpa);

    p->id = 999;
    printf("after edit:  id=%d\n", r.id);
    return 0;
}
