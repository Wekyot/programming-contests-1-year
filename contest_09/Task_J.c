#include <stdlib.h>
#include "tree.h"

struct tree_t *bst_insert(
    struct tree_t *root,
    int key
){
    struct tree_t** cur = &root;

    while (*cur){
        if (key < (*cur)->key) cur = &(*cur)->left;
        else if (key > (*cur)->key) cur = &(*cur)->right;
        else return root;
    }

    struct tree_t* new_node = malloc(sizeof(struct tree_t));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    *cur = new_node;
    return root;
}