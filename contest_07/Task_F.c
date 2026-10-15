#include "types.h"
#include <stdio.h>

struct FileStats file_stats(FILE *file){
    struct FileStats res = {0,0,0};

    
    int c;
    int last_c;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF){
        res.characters++;
        if (c == ' ' || c == '\t' || c == '\n'){
            in_word = 0;
        }
        else {
            if (in_word == 0){
                in_word = 1;
                res.words++;
            }
        }
        if (c == '\n'){
            res.lines++;
        }

        last_c = c;
    }

    if (res.characters > 0 && last_c != '\n'){
        res.lines++;
    }
    
    return res;
}