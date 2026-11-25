int moveright(int *array, int key, int last){
    if (last <= 0) return 0;

    int *cur_ptr = array + last - 1;
    
    while (cur_ptr >= array && *cur_ptr > key) {
        *(cur_ptr + 1) = *cur_ptr;
        cur_ptr--;
    }

    return (cur_ptr - array) + 1;
}