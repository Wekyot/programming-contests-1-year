#include "tree.h"

void tree_clear(struct node *root){
    if (root == NULL) return;
    tree_clear(root->left);
    tree_clear(root->right);

    free(root);
}