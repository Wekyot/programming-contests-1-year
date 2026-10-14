#include "types.h"

struct Point midpoint(struct Point a, struct Point b){
    struct Point result;
    result.x = (a.x + b.x) / 2;
    result.y = (a.y + b.y) / 2;

    return result;
}