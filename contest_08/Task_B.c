#include <string.h>
#include <stdlib.h>
#include "types.h"

int selection_step(
    void *array,
    size_t element_size,
    size_t count,
    size_t first_unsorted,
    cmp_t compare
) {
    char *base = (char *)array;
    char *unsorted_start = base + first_unsorted * element_size;
    char *array_end = base + count * element_size;
    char *min_ptr = unsorted_start;

    for (char *arr_ptr = unsorted_start + element_size; arr_ptr < array_end; arr_ptr += element_size) {
        if (compare(arr_ptr, min_ptr) < 0) {
            min_ptr = arr_ptr;
        }
    }

    if (min_ptr != unsorted_start) {
        void *temp = malloc(element_size);
        if (!temp) return -1;

        memcpy(temp, unsorted_start, element_size);
        memcpy(unsorted_start, min_ptr, element_size);
        memcpy(min_ptr, temp, element_size);

        free(temp);
    }

    return 0;
}
