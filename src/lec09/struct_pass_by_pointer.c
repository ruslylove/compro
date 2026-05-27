#include <stdio.h>

typedef struct { int x, y; } Point;

void move_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void print_point(const Point *p) {
    printf("(%d, %d)\n", p->x, p->y);
}

int main(void) {
    Point p1 = {10, 20};
    print_point(&p1);
    move_point(&p1, 5, 5);
    print_point(&p1);
    return 0;
}
