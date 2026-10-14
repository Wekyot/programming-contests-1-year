#include "types.h"
#include <stdio.h>
#include <string.h>

int compare_results(void const *left, void const *right){
    struct Result a = *(struct Result const *)left;
    struct Result b = *(struct Result const *)right;

    if (a.solved > b.solved) return -1;
    if (a.solved < b.solved) return 1;
    
    if (a.penalty < b.penalty) return -1;
    if (a.penalty > b.penalty) return 1;

    return strcmp(a.name, b.name);
}