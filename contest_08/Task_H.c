#include <stddef.h>
#include <stdlib.h>
#include "types.h"

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

int id_cmp(void const* lhs, void const* rhs){
    int const* larg = (int*) lhs;
    int const* rarg = (int*) rhs;

    if (*larg > *rarg) return 1;
    if (*larg < *rarg) return -1;
    return 0;
}

struct Product const *find_product(
    struct Product const *products,
    size_t count,
    int id
){
    void const* key = &id;
    void const* id_result = generic_binary_search(
                                key,
                                (void const*) &products->id,
                                count,
                                sizeof(struct Product),
                                id_cmp);

    struct Product const* product_result = container_of(id_result, struct Product, id);

    return product_result;
}