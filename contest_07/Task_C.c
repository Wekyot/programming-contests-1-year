#include <stdio.h>

struct Point {
    double x;
    double y;
};

struct Rectangle {
    struct Point left_bottom;
    struct Point right_top;
};

int max(int a, int b){
    return a >= b ? a : b;
}

int min(int a, int b){
    return a <= b ? a : b;
}

int intersection(struct Rectangle a, struct Rectangle b, struct Rectangle *result){
    struct Rectangle res;

    res.left_bottom.x = max(a.left_bottom.x, b.left_bottom.x);
    res.left_bottom.y = max(a.left_bottom.y, b.left_bottom.y);
    res.right_top.x = min(a.right_top.x, b.right_top.x);
    res.right_top.y = min(a.right_top.y, b.right_top.y);

    if (res.right_top.x > res.left_bottom.x && res.right_top.y > res.left_bottom.y){
        *result = res;
        return 1;
    }
    else {
        return 0;
    }
}

int main(void){
    struct Rectangle a;
    struct Rectangle b;

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a.left_bottom.x, &a.left_bottom.y, &a.right_top.x, &a.right_top.y, &b.left_bottom.x, &b.left_bottom.y, &b.right_top.x, &b.right_top.y);

    struct Rectangle result;

    if (intersection(a,b,&result)){
        printf("YES\n%.1lf %.1lf %.1lf %.1lf\n",result.left_bottom.x, result.left_bottom.y, result.right_top.x, result.right_top.y);
    }
    else {
        printf("NO\n");
    }

    return 0;
}