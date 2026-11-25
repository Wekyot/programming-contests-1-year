#include "tree.h"

size_t count_single_child(
    struct tree_t const *root
){
    if (root == NULL) return 0;
    if ((!root->left && !root->right)) return 0;
    if (root->left && !root->right)
        return count_single_child(root->left) + 1;
    if (!root->left && root->right)
        return count_single_child(root->right) + 1;

    return count_single_child(root->left) + count_single_child(root->right);
}