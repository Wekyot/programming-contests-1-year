#include "tree.h"

struct node const *bst_next(struct node const *root, int32_t key){
    struct node const* closest_next = NULL;
    while (root != NULL){
        if (root->key > key) closest_next = root;

        if (key >= root->key) root = root->right;
        else if (key < root->key) root = root->left;
    }
    return closest_next;
}
struct node const *bst_prev(struct node const *root, int32_t key){
    struct node const* closest_prev = NULL;
    while (root != NULL){
        if (root->key < key) closest_prev = root;

        if (key > root->key) root = root->right;
        else if (key <= root->key) root = root->left;
    }
    return closest_prev;
}