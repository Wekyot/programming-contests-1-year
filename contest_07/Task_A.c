#include <stdio.h>

struct Point {
    double x;
    double y;
};

struct Point midpoint(struct Point a, struct Point b){
    struct Point result;
    result.x = (a.x + b.x) / 2;
    result.y = (a.y + b.y) / 2;

    return result;
}

int main(void){
    struct Point a;
    struct Point b;

    scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);

    struct Point m = midpoint(a,b);

    printf("%.1lf %.1lf",m.x,m.y);

    return 0;
}