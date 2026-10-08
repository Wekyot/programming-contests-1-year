#include <string.h>

int parse_args(int argc, char *argv[], int *command){
    int flag = -1;

    if (argc == 2 && !strcmp(argv[1],"--help")){
        flag = 0;
    }
    else if (argc == 3 && !strcmp(argv[1],"schema")){
        flag = 1;
    }
    else if (argc == 3 && !strcmp(argv[1],"stats")){
        flag = 2;
    }
    else if (argc == 4 && !strcmp(argv[1],"report")){
        flag = 3;
    }

    if (flag != -1){
        *(command) = flag;
        return 1;
    }
    else {
        return 0;
    }
}