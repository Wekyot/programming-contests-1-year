#include <stdio.h>
#include <ctype.h>

enum {
    STATE_START,
    STATE_SIGN,
    STATE_INT_DIG,
    STATE_DOT,
    STATE_DBL_DIG,
    STATE_FAIL
};

int main(){
    int state = STATE_START;
    char a;

    while (1){
        a = getchar();
        if (a == '\n' || a == EOF){
            break;
        }

        switch (state){
            case STATE_START:
                if (a == '+' || a == '-') {
                    state = STATE_SIGN;
                } else if (isdigit(a)) {
                    state = STATE_INT_DIG;
                } else {
                    state = STATE_FAIL;
                }
                break;

            case STATE_SIGN:
                if (isdigit(a)) {
                    state = STATE_INT_DIG;
                } else {
                    state = STATE_FAIL;
                }
                break;

            case STATE_INT_DIG:
                if (isdigit(a)) {
                    state = STATE_INT_DIG;
                } else if (a == '.') {
                    state = STATE_DOT;
                } else {
                    state = STATE_FAIL;
                }
                break;

            case STATE_DOT:
                if (isdigit(a)) {
                    state = STATE_DBL_DIG;
                } else {
                    state = STATE_FAIL;
                }
                break;

            case STATE_DBL_DIG:
                if (isdigit(a)) {
                    state = STATE_DBL_DIG;
                } else {
                    state = STATE_FAIL;
                }
                break;

            case STATE_FAIL:
                break;
        }

        if (state == STATE_FAIL){
            break;
        }
    }

    if (state == STATE_INT_DIG){
        printf("INT\n");
    }
    else if (state == STATE_DBL_DIG){
        printf("DOUBLE\n");
    }
    else {
        printf("STRING\n");
    }
    

    return 0;
}