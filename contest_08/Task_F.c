#include <stdlib.h>

size_t count_in_range(
    int const *first,
    int const *last,
    int left,
    int right
){
    int const* left_border;
    int const* right_border;

    int const* orig_first = first;
    int const* orig_last = last;

    while (last > first){
        if (left > *(first + (last - first)/2)){
            first = first + (last - first)/2 + 1;
        }
        else {
            last = first + (last - first)/2;
        }
    }

    left_border = first;

    first = orig_first;
    last = orig_last;

    while (last > first){
        if (right >= *(first + (last - first)/2)){
            first = first + (last - first)/2 + 1;
        }
        else {
            last = first + (last - first)/2;
        }
    }

    right_border = first;

    return right_border - left_border;
}