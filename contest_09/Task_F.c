#include "tree.h"

int is_bst(struct tree_t const *root){
    if (!root) return 1;
    if (!root->left && !root->right) return 1;
    if (root->left && !root->right) return (root->left->key < root->key) && is_bst(root->left);
    if (!root->left && root->right) return (root->right->key > root->key) && is_bst(root->right);

    return (root->left->key < root->key) && is_bst(root->left) && (root->right->key > root->key) && is_bst(root->right);
}