int const *binary_find(
    int const *first,
    int const *last,
    int value
){
    int const* orig_last = last;

    while (last > first){
        if (value > *(first + (last - first)/2)){
            first = first + (last - first)/2 + 1;
        }
        else {
            last = first + (last - first)/2;
        }
    }

    if (value == *first){
        return first;
    }
    else return orig_last;
}