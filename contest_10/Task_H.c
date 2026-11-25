#include "tree.h"

size_t range_count(
    struct node const *root,
    int32_t left,
    int32_t right
){
    if (left > right) return 0;

    size_t result = 0;
    struct node const *curr = root;
    while (curr){
        if (right < curr->key){
            curr = curr->left;
        }
        else if (right >= curr->key){
            result += (curr->left ? curr->left->size : 0) + 1;
            curr = curr->right;
        }
    }
    curr = root;
    while (curr){
        if (left <= curr->key){
            curr = curr->left;
        }
        else if (left > curr->key){
            result -= (curr->left ? curr->left->size : 0) + 1;
            curr = curr->right;
        }
    }

    return result;
}