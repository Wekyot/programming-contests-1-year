#include "types.h"
#include <stdio.h>
#include <stdlib.h>

size_t read_students(FILE *file, struct Student **students){
    size_t count = 0;

    int c;
    int cur_len = 0;
    struct Student* stud = malloc(sizeof(struct Student) * 10000);

    while ((c = fgetc(file)) != EOF){
        if (c == ' '){
            fscanf(file,"%d",&((*(stud + count)).score));
            cur_len = 0;
        }
        else if (c == '\n'){
            count++;
        }
        else {
            (*(stud + count)).name[cur_len] = c;
            cur_len++;
        }
    }

    if (count == 0){
        *students = NULL;
        free(stud);
    }
    else {
        *students = stud;
    }
    return count;
}