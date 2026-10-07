#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100000

typedef enum {
    STATE_START,
    STATE_SIGN,
    STATE_INT_DIG,
    STATE_DOT,
    STATE_DBL_DIG,
    STATE_FAIL
} State;

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

State spot_state_column(void){
    State result = STATE_INT_DIG;
    int n;
    scanf("%d",&n);
    getchar();
    char* buffer = malloc(BUFFER_SIZE * sizeof(char));

    for (int i = 0;i < n;i++){
        fgets(buffer, BUFFER_SIZE, stdin);
        State ret_res = spot_state(buffer);
        
        switch (result)
        {
        case STATE_START:
            result = ret_res;
            break;
        case STATE_INT_DIG: case STATE_DBL_DIG:
            if (ret_res > result){
                result = ret_res;
            }
            break;
        case STATE_FAIL:
            break;
        }

        if (result == STATE_FAIL){
            break;
        }
    }
    
    free(buffer);

    return result;
}

int main(){
    switch (spot_state_column()){
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

    return 0;
}