#include "mylist.h"
#include <stdlib.h>

struct node_t *reverse(struct node_t *head){
    struct node_t *prev = NULL;
    struct node_t *cur = head;
    struct node_t *next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}