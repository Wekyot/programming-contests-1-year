#include <stdio.h>

unsigned my_rand(void){
    static unsigned int state = 1;
    state = (37 * state + 17) % 1000003;
    return state;
}

int main(void){
    printf("%u",my_rand());
    printf("%u",my_rand());

    return 0;
}