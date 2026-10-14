#include <stdio.h>
#include <stdlib.h>

struct Term {
    long long coefficient;
    int degree;
};

size_t normalize_polynomial(struct Term *terms, size_t size){
    if (size <= 0){
        return 0;
    }

    size_t new_size = size;

    for (size_t i = 0;i < new_size - 1;i++){
        int flag = 0;

        for (size_t j = 0;j < new_size - 1 - i;j++){
            if ((terms + j)->degree < (terms + j + 1)->degree){
                //printf("[Swapping elemets %lld %d and %lld %d]\n",(*(terms + j)).coefficient,(*(terms + j)).degree,(*(terms + j + 1)).coefficient,(*(terms + j + 1)).degree);

                struct Term temp = *(terms + j);
                *(terms + j) = *(terms + j + 1);
                *(terms + j + 1) = temp;

                flag = 1;
            }
        }

        if (!flag){
            break;
        }
    }

    for (size_t i = 0;i < new_size - 1;i++){
        if ((terms + i)->degree == (terms + i + 1)->degree){
            //printf("[Summing elements degree %d with coefs %lld and %lld resulting %lld]\n",(*(terms + i)).degree, (*(terms + i)).coefficient, (*(terms + i + 1)).coefficient, (*(terms + i)).coefficient + (*(terms + i + 1)).coefficient);

            (*(terms + i)).coefficient += (*(terms + i + 1)).coefficient;

            //printf("[...but real result is %lld]\n", (*(terms + i)).coefficient);

            for (size_t j = i + 1;j < new_size - 1;j++){
                *(terms + j) = *(terms + j + 1);
            }
            new_size--;
            i--;
            continue;
        }
    }

    for (size_t i = 0; i < new_size;i++){
        if ((terms + i)->coefficient == 0){
            //printf("[Deleted element %lld %d]\n",(*(terms + i)).coefficient,(*(terms + i)).degree);
            
            for (size_t j = i;j < new_size - 1;j++){
                *(terms + j) = *(terms + j + 1);
            }
            new_size--;
            i--;
            continue;
        }
    }

    return new_size;
}

int main(void){
    size_t size;
    scanf("%llu",&size);

    struct Term terms[size];
    for (size_t i = 0;i < size;i++){
        scanf("%lld %d",&(*(terms + i)).coefficient,&(*(terms + i)).degree);
    }

    size = normalize_polynomial(terms, size);

    printf("%llu\n",size);
    for (size_t i = 0;i < size;i++){
        printf("%lld %d\n",(*(terms + i)).coefficient,(*(terms + i)).degree);
    }

    return 0;
}