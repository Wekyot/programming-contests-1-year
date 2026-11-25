#include <stdlib.h>
#include "intlist.h"

size_t int_list_remove_all(IntList *list, int value){
    size_t removed = 0;

    struct node_t* prev = NULL;
    struct node_t* cur = list->head;
    struct node_t* next = NULL;

    while (cur != NULL){
        if (cur->data == value){
            next = cur->next;
            free(cur);
            if (prev){
                prev->next = next;
            }
            else {
                list->head = next;
            }

            if (next == NULL){
                list->tail = prev;
            }

            removed++;

            cur = next;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }

    list->size -= removed;
    return removed;
}