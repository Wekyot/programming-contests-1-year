#include <stdio.h>
#include <stdlib.h>

void backtracking_func(char* cur_str, int cur_len, int open_count, int close_count, int n){
    if (n * 2 == cur_len){
        cur_str[cur_len] = '\0';
        printf("%s\n",cur_str);
        return;
    }
    
    if (open_count < n){
        cur_str[cur_len] = '(';
        backtracking_func(cur_str,cur_len + 1,open_count + 1,close_count,n);
    }

    if (close_count < open_count){
        cur_str[cur_len] = ')';
        backtracking_func(cur_str,cur_len + 1,open_count,close_count + 1,n);
    }
}

int main(void){
    int n;
    scanf("%d",&n);

    char* buffer = (char*) malloc(sizeof(char) * (2 * n + 1));
    backtracking_func(buffer,0,0,0,n);
    
    free(buffer);

    return 0;
}