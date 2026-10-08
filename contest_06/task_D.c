#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100000
#define MAX_COLUMNS 100
#define STRING_COUNT_STEP 1000
#define STRING_LEN_STEP 10000

typedef enum {
    STATE_START,
    STATE_SIGN,
    STATE_INT_DIG,
    STATE_DOT,
    STATE_DBL_DIG,
    STATE_FAIL
} State;

State spot_state(char* str);
void field_split(char** array, State* states_arr);


int main(void){
    int n;
    scanf("%d",&n);
    getchar();

    char** titles_array = (char**) malloc(sizeof(char*) * MAX_COLUMNS);
    char* titles_string = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    fgets(titles_string, BUFFER_SIZE, stdin);
    titles_string[strcspn(titles_string, "\n")] = '\0';

    const char delims[] = ",";
    char* token = strtok(titles_string, delims);
    int column_number = 0;

    for (int i = 0;token != NULL;i++){
        *(titles_array + i) = (char*) malloc(sizeof(char) * STRING_LEN_STEP);

        strcpy(*(titles_array + i), token);
        column_number++;
        token = strtok(NULL, delims);
    }

    free(titles_string);

    State* states_arr = (State*) malloc(sizeof(State) * column_number);
    for (int i = 0;i < column_number;i++){
        *(states_arr + i) = STATE_START;
    }

    char** array = (char**) malloc(sizeof(char*) * column_number);
    for (int i = 0;i < column_number;i++){
        *(array + i) = (char*) malloc (sizeof(char) * STRING_LEN_STEP);
    }

    for (int i = 0;i < n;i++){
        field_split(array,states_arr);
    }

    for (int i = 0;i < column_number;i++){
        printf("%s ",*(titles_array + i));
        switch (*(states_arr + i)){
            case STATE_INT_DIG:
                printf("INT\n");
                break;
            case STATE_DBL_DIG:
                printf("DOUBLE\n");
                break;
            case STATE_FAIL:
                printf("STRING\n");
                break;
        }

        free(*(titles_array + i));
    }

    for (int i = 0;i < column_number;i++){
        free(*(array + i));
    }
    free(array);
    free(titles_array);
    free(states_arr);

    return 0;
}

State spot_state(char* str){
    State result = STATE_START;
    char c;
    int i = 0;

    while (1){
        c = *(str + i++);

        if (c == '\0' || c == '\n'){
            if (result == STATE_DOT || result == STATE_START){
                result = STATE_FAIL;
            }
            return result;
        }

        switch (result){
            case STATE_START:
                if (c == '+' || c == '-') {
                    result = STATE_SIGN;
                } else if (isdigit(c)) {
                    result = STATE_INT_DIG;
                } else {
                    result = STATE_FAIL;
                }
                break;

            case STATE_SIGN:
                if (isdigit(c)) {
                    result = STATE_INT_DIG;
                } else {
                    result = STATE_FAIL;
                }
                break;

            case STATE_INT_DIG:
                if (isdigit(c)) {
                    result = STATE_INT_DIG;
                } else if (c == '.') {
                    result = STATE_DOT;
                } else {
                    result = STATE_FAIL;
                }
                break;

            case STATE_DOT:
                if (isdigit(c)) {
                    result = STATE_DBL_DIG;
                } else {
                    result = STATE_FAIL;
                }
                break;

            case STATE_DBL_DIG:
                if (isdigit(c)) {
                    result = STATE_DBL_DIG;
                } else {
                    result = STATE_FAIL;
                }
                break;

            case STATE_FAIL:
                break;
        }

        if (result == STATE_FAIL){
            break;
        }
    }

    return result;
}

void field_split(char** array, State* states_arr){

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
            case EOF: case '\n':
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
                    //*(array + cur_string_num) = (char*) malloc (sizeof(char) * STRING_LEN_STEP);      выделили заранее в main
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

    for (int i = 0;i < cur_string_num;i++){
        State cur_state = spot_state(*(array + i));
        if (cur_state > *(states_arr + i)){
            *(states_arr + i) = cur_state;
        }
    }

    return;
}