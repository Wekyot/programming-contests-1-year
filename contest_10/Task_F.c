#include "tree.h"

static unsigned check_node(
    struct node const *root,
    struct node const *min,
    struct node const *max,
    int *real_height,
    size_t *real_size
) {
    if (!root) {
        *real_height = 0;
        *real_size = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    size_t ls = 0, rs = 0;

    unsigned result = check_node(root->left, min, root, &lh, &ls)
                    | check_node(root->right, root, max, &rh, &rs);

    int cur_h = (lh > rh ? lh : rh) + 1;
    size_t cur_s = ls + rs + 1;

    *real_height = cur_h;
    *real_size = cur_s;

    if ((min && !(root->key > min->key)) || (max && !(root->key < max->key))) {
        result |= 1;
    }

    if (root->height != cur_h) {
        result |= (1 << 1);
    }

    if (root->size != cur_s) {
        result |= (1 << 2);
    }

    int diff = lh > rh ? lh - rh : rh - lh;
    if (diff >= 2) {
        result |= (1 << 3);
    }

    return result;
}

unsigned check_tree(struct node const *root) {
    int h = 0;
    size_t s = 0;
    return check_node(root, NULL, NULL, &h, &s);
}
