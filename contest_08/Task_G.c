#include "types.h"

void const *generic_binary_search(
    void const *key,
    void const *base,
    size_t count,
    size_t element_size,
    cmp_t compare
){
    char const* left = (char const*) base;
    char const* right = (char const*) base + count * element_size;

    while (right > left){
        char const* mid = left + ((right - left) / element_size / 2) * element_size;
        if (compare((void*) mid, key) < 0){
            left = mid + element_size;
        }
        else {
            right = mid;
        }
    }

    if (compare((void*) left, key) == 0){
        return (void*) left;
    }
    else {
        return (char const*) base + count * element_size;
    }
}