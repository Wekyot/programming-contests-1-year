#include "tree.h"

int distance_to_child(struct tree_t const *root, int key){
    if (root == NULL) return -100;
    if (root->key == key) return 1;
    if (key > root->key) return distance_to_child(root->right, key) + 1;
    if (key < root->key) return distance_to_child(root->left, key) + 1;

    return 0;
}

int bst_distance(
    struct tree_t const *root,
    int first,
    int second
){
    struct tree_t const *cur_root = root;
    while (cur_root){
        if (first < cur_root->key && second < cur_root->key)
            cur_root = cur_root->left;
        else if (first > cur_root->key && second > cur_root->key)
            cur_root = cur_root->right;
        else break;
    }

    int result = distance_to_child(cur_root, first) + distance_to_child(cur_root, second) - 2;
    if (result < 0)
        return -1;
    else return result;
}