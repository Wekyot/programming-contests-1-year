#include "tree.h"

struct node const *kth(struct node const *root, size_t k){
    if (!root || (root && k >= root->size)) return NULL;
    while (root){
        size_t ls = root->left ? root->left->size : 0;

        if (k < ls){
            root = root->left;
        }
        else if (k > ls){
            k -= ls + 1;
            root = root->right;
        }
        else break;
    }
    return root;
}
size_t rank(struct node const *root, int32_t key){
    size_t result = 0;
    while (root){
        if (key < root->key){
            root = root->left;
        }
        else if (key > root->key){
            result += (root->left ? root->left->size : 0) + 1;
            root = root->right;
        }
        else {
            result += (root->left ? root->left->size : 0);
            break;
        }
    }
    return result;
}