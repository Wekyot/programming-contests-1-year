#include "tree.h"

void update_node(struct node *node){
    if (node == NULL) return;
    int lh = node->left ? node->left->height : 0;
    int rh = node->right ? node->right->height : 0;
    size_t ls = node->left ? node->left->size : 0;
    size_t rs = node->right ? node->right->size : 0;
    node->height = (lh > rh ? lh : rh) + 1;
    node->size = ls + rs + 1;
}