#include <stdio.h>
#include <stdlib.h>

#define STRING_COUNT_STEP 1000
#define STRING_LEN_STEP 10000

int main(void){
    char** array = (char**) malloc(sizeof(char*) * STRING_COUNT_STEP);
    *(array + 0) = (char*) malloc (sizeof(char) * STRING_LEN_STEP);
    int cur_string_num = 0;
    int cur_string_len = 0;
    char* cur_string = *(array + 0);

    char a;
    int exit_flag = 0;
    int outer_quote_flag = 0;
    int was_quote_flag = 0;

    while (!exit_flag){
        scanf("%c",&a);
        
        switch (a){
            case '\n':
                exit_flag = 1;
                cur_string [cur_string_len] = '\0';
                cur_string_num++;

                break;
            case ',':
                if (was_quote_flag || !outer_quote_flag){
                    outer_quote_flag = 0;
                    was_quote_flag = 0;

                    cur_string [cur_string_len] = '\0';
                    cur_string_len = 0;
                    cur_string_num++;
                    *(array + cur_string_num) = (char*) malloc (sizeof(char) * STRING_LEN_STEP);
                    cur_string = *(array + cur_string_num);
                }
                else{
                    cur_string [cur_string_len] = a;
                    cur_string_len++;
                }
                break;

            case '"':
                if (!outer_quote_flag){
                    outer_quote_flag = 1;
                    was_quote_flag = 0;
                }
                else{
                    if (!was_quote_flag){
                        was_quote_flag = 1;
                    }
                    else{
                        cur_string [cur_string_len] = a;
                        cur_string_len++;
                        was_quote_flag = 0;
                    }
                }
                break;

            default:
                cur_string [cur_string_len] = a;
                cur_string_len++;
                break;
        }
    }

    printf("%d\n",cur_string_num);
    for (int i = 0;i < cur_string_num;i++){
        printf("%s\n",*(array + i));
        free(*(array + i));
    }
    free(array);

    return 0;
}
