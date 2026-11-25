#include "tree.h"

struct tree_t const *bst_find(
    struct tree_t const *root,
    int key
){
    while (root){
        if (key < root->key) root = root->left;
        else if (key > root->key) root = root->right;
        else return root;
    }
}