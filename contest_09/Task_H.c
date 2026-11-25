#include "tree.h"

int mirror_equal(
    struct tree_t const *first,
    struct tree_t const *second
){
    if (first == NULL && second == NULL) return 1;
    if (!first != !second) return 0;
    else return (first->key == second->key) && mirror_equal(first->left, second->right) && mirror_equal(first->right, second->left);
}