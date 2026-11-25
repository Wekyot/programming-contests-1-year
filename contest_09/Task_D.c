#include <stdlib.h>
#include "tree.h"

size_t write_postorder(
    struct tree_t const *root,
    int *output
){
    if (root == NULL){
        return 0;
    }
    else if (root->left == NULL && root->right == NULL){
        *output = root->key;
        return 1;
    }

    int* new_output = output;
    new_output += write_postorder(root->left, new_output);
    new_output += write_postorder(root->right, new_output);
    *(new_output) = root->key;
    new_output++;
    
    return new_output - output;
}