#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

struct node_t *read_list(FILE *input){
    int cur_data;
    struct node_t* head = NULL;
    if (fscanf(input,"%d",&cur_data) == 1){
        head = malloc (sizeof(struct node_t));
        head->data = cur_data;
        head->next = NULL;
        struct node_t* cur_node = head;
        while (fscanf(input,"%d",&cur_data) == 1){
            struct node_t* temp = malloc (sizeof(struct node_t));
            temp->data = cur_data;
            temp->next = NULL;
            cur_node->next = temp;
            cur_node = temp;
        }

        cur_node = head;
        struct node_t* last_even = NULL;
        struct node_t* prev_node = NULL;

        while (cur_node != NULL){
            struct node_t* next_node = cur_node->next;

            if (cur_node->data % 2 == 0){
                if (prev_node != last_even){
                    prev_node->next = next_node;

                    if (last_even == NULL) {
                        cur_node->next = head;
                        head = cur_node;
                    } else {
                        cur_node->next = last_even->next;
                        last_even->next = cur_node;
                    }
                }
                else {
                    prev_node = cur_node;
                }

                last_even = cur_node;
            }
            else {
                prev_node = cur_node;
            }
            cur_node = cur_node->next;
        }
    }
    return head;
}

void delete_list(struct node_t *head){
    while (head != NULL){
        struct node_t* temp = head->next;
        free(head);
        head = temp;
    }
}