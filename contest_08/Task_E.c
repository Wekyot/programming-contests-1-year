int const *lower_bound_int(
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

    return first;
}