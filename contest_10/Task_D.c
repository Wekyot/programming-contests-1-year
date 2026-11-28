#include "tree.h"

struct node *rotate_r(struct node *node){
    if (!node) return NULL;
    struct node *new_root = node->left;

    node->left = new_root->right;
    new_root->right = node;

    return new_root;
}

struct node *rotate_l(struct node *node){
    if (!node) return NULL;
    struct node *new_root = node->right;

    node->right = new_root->left;
    new_root->left = node;

    return new_root;
}

int height(struct node const *root){
    return root ? root->height : 0;
}

size_t size(struct node const *root){
    return root ? root->size : 0;
}

void update(struct node *root){
    if (!root) return;
    update(root->left);
    update(root->right);

    root->height = (height(root->left) > height(root->right) ? height(root->left) : height(root->right)) + 1;
    root->size = size(root->right) + size(root->left) + 1;
}

struct node *rebalance(struct node *root){
    if (!root) return NULL;
    int balance = height(root->left) - height(root->right);

    if (balance == -2){
        if (height(root->right->left) > height(root->right->right)){
            root->right = rotate_r(root->right);
        }
        root = rotate_l(root);
    }
    else if (balance == 2){
        if (height(root->left->left) < height(root->left->right)){
            root->left = rotate_l(root->left);
        }
        root = rotate_r(root);
    }
    update(root);
    return root;
}