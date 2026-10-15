#include <stdio.h>
#include <string.h>

size_t filter_lines(FILE *input, FILE *output, char const *pattern){
    size_t count = 0;
    char cur_str[256];
    int cur_len = 0;

    int c;
    while ((c = getc(input)) != EOF){
        if (c != '\n'){
            cur_str[cur_len] = c;
            cur_len++;
        }
        else {
            cur_str[cur_len] = '\0';
            if (strstr(cur_str,pattern)){
                fprintf(output,"%s\n",cur_str);
                printf("%s\n",cur_str);
                count++;
            }
            cur_len = 0;
        }
    }

    cur_str[cur_len] = '\0';
    if (strstr(cur_str,pattern)){
        fprintf(output,"%s\n",cur_str);
        count++;
    }

    return count;
}

int main(void){
    FILE* input = fopen("in.txt","r");
    FILE* output = fopen("out.txt","w");
    printf("%llu\n",filter_lines(input, output, "world"));

    fclose(input);
    fclose(output);

    return 0;
}