#include <stdarg.h>

size_t count_if_args(int (*predicate)(int), size_t count, ...){
    size_t matched = 0;

    va_list args;
    va_start(args,count);

    for (size_t i = 0;i < count;i++){
        int cur_number = va_arg(args,int);

        if (predicate(cur_number) != 0){
            matched++;
        }
    }

    va_end(args);

    return matched;
}