#include "types.h"

void answer_queries(
    struct node const *root,
    struct query const *queries,
    size_t count,
    int64_t *answers
){
    for (int32_t i = 0; i < count; ++i) {
        struct query const *curq = &queries[i];
        struct node const *curr = root;

        switch (curq->type){
            case QUERY_NEXT:
                struct node const *closest_next = NULL;
                while(curr){
                    if (curq->a < curr->key && (!closest_next || curr->key < closest_next->key)){
                        closest_next = curr;
                    }
                    if (curq->a < curr->key){
                        curr = curr->left;
                    }
                    else if (curq->a >= curr->key){
                        curr = curr->right;
                    }
                }
                if (closest_next){
                    answers[i] = closest_next->key;
                }
                else {
                    answers[i] = INT64_MIN;
                } 
                break;
            case QUERY_PREV:
                struct node const *closest_prev = NULL;
                while(curr){
                    if (curq->a > curr->key && (!closest_prev || curr->key > closest_prev->key)){
                        closest_prev = curr;
                    }
                    if (curq->a <= curr->key){
                        curr = curr->left;
                    }
                    else if (curq->a > curr->key){
                        curr = curr->right;
                    }
                }
                if (closest_prev){
                    answers[i] = closest_prev->key;
                }
                else {
                    answers[i] = INT64_MIN;
                } 
                break;
            case QUERY_KTH:
                ;
                int32_t k = curq->a;
                if (!curr || (curr && k >= curr->size)){
                    answers[i] = INT64_MIN;
                    break;
                }

                while(curr){
                    size_t ls = curr->left ? curr->left->size : 0;

                    if (k < ls){
                        curr = curr->left;
                    }
                    else if (k > ls){
                        k -= ls + 1;
                        curr = curr->right;
                    }
                    else break; 
                }
                answers[i] = curr->key;
                break;
            case QUERY_RANK:
                ;
                int64_t result = 0;
                int32_t key = curq->a;

                while (curr){
                    if (key < curr->key){
                        curr = curr->left;
                    }
                    else if (key > curr->key){
                        result += (curr->left ? curr->left->size : 0) + 1;
                        curr = curr->right;
                    }
                    else {
                        result += (curr->left ? curr->left->size : 0);
                        break;
                    }
                }
                answers[i] = result;
                break;
            case QUERY_RANGE_COUNT:
                if (curq->a > curq->b) {
                    answers[i] = 0;
                    break;
                }

                int64_t rresult = 0;
                while (curr){
                    if (curq->b < curr->key){
                        curr = curr->left;
                    }
                    else if (curq->b >= curr->key){
                        rresult += (curr->left ? curr->left->size : 0) + 1;
                        curr = curr->right;
                    }
                }
                curr = root;
                while (curr){
                    if (curq->a <= curr->key){
                        curr = curr->left;
                    }
                    else if (curq->a > curr->key){
                        rresult -= (curr->left ? curr->left->size : 0) + 1;
                        curr = curr->right;
                    }
                }

                answers[i] = rresult;
                break;
        }
    }
}