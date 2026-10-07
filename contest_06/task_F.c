size_t count_if(int const *array, size_t size, int (*predicate)(int)){
    size_t count = 0;

    for (int i = 0;i < size;i++){
        if (predicate(*(array + i)) != 0){
            count++;
        }
    }

    return count;
}