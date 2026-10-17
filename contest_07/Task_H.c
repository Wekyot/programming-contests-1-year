#include <stdio.h>

size_t merge_files(FILE *first, FILE *second, FILE *output){
    size_t count = 0;
    int a,b;
    
    int a_end = (fscanf(first,"%d",&a) == 1);
    int b_end = (fscanf(second,"%d",&b) == 1);

    while (a_end || b_end){

        if (a_end && b_end){
            if (a < b){
                fprintf(output,"%d\n",a);
                a_end = (fscanf(first,"%d",&a) == 1);
            }
            else {
                fprintf(output,"%d\n",b);
                b_end = (fscanf(second,"%d",&b) == 1);
            }
        }
        else if (a_end){
            fprintf(output,"%d\n",a);
            a_end = (fscanf(first,"%d",&a) == 1);
        }
        else if (b_end){
            fprintf(output,"%d\n",b);
            b_end = (fscanf(second,"%d",&b) == 1);
        }

        count++;
    }

    return count;
}

int main(void){
    FILE* input1 = fopen("in.txt","r");
    FILE* input2 = fopen("in2.txt","r");
    FILE* output = fopen("out.txt","w");
    printf("%llu\n",merge_files(input1, input2, output));

    fclose(input1);
    fclose(input2);
    fclose(output);

    return 0;
}