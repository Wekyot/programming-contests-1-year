#include <stdlib.h>
#include "mylist.h"

size_t loop_len(struct node_t const *top){
    if (top == NULL || top->next == NULL || top->next->next == NULL){
        return 0;
    }

    struct node_t const* slow = top->next;
    struct node_t const* fast = top->next->next;

    while (slow != NULL && fast != NULL && slow != fast && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == NULL || fast == NULL || fast->next == NULL){
        return 0;
    }

    int index = 0;
    slow = top;
    while (slow != fast){
        slow = slow->next;
        fast = fast->next;
        index++;
    }

    size_t len = 1;
    fast = slow->next;
    while (slow != fast){
        fast = fast->next;
        len++;
    }

    return len;
}