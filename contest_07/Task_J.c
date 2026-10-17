#include "types.h"
#include <stdio.h>
#include <stdlib.h>

int read_record(FILE *file, size_t index, struct Record *result){
    if (
    fseek(file, sizeof(struct Record) * index, SEEK_SET) ||
    (fread(result, sizeof(struct Record), 1, file) != 1)
    )
    {
        return 0;
    }
    else {
        return 1;
    }
}