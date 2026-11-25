#include "types.h"

size_t cycle_len(generator_t gen){
    int slow = gen(0);
    int fast = gen(gen(0));

    while (slow != fast){
        slow = gen(slow);
        fast = gen(gen(fast));
    }

    int index = 0;
    slow = 0;
    while (slow != fast){
        slow = gen(slow);
        fast = gen(fast);
        index++;
    }

    size_t len = 1;
    fast = gen(slow);
    while (slow != fast){
        fast = gen(fast);
        len++;
    }

    return len;
}