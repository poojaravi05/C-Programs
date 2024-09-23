#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x, y;
}Point;
/*
Point getMidPoint(Point a, Point b){
    Point m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int main(){
    Point p1 = {
        .x = 1,
        .y = 1
    };
    Point p2 = {
        .x = 3,
        .y = 2
    };
    Point mid;
    mid = getMidPoint(p1, p2);
    printf("%lf, %lf\n", mid.x, mid.y);
    return 0;
}
*/
// For better efficiency for large structures, we use pointers to optimize

Point* getMidPoint(const Point* a, const Point* b){
    Point* m = malloc(sizeof(Point));
    m->x = (a->x + b->x) / 2;
    m->y = (a->y + b->y) / 2;
    return m;
}

int main(){
    Point p1 = {
        .x = 1,
        .y = 1
    };
    Point p2 = {
        .x = 3,
        .y = 2
    };
    Point* mid = getMidPoint(&p1, &p2);
    printf("%lf, %lf\n", mid->x, mid->y);
    free(mid);
    return 0;
}