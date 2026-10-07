#include <stdio.h>

int main(void){
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);

    int cache_miss_row = (n * m + k - 1) / k;
    int cache_miss_column = 0;
    int cur_cache_line = -1;

    for (int j = 0;j < m;j++){
        for (int i = 0;i < n;i++){
            int linear_index = i * m + j;
            int required_cache_line = linear_index / k;

            if (required_cache_line != cur_cache_line){
                cache_miss_column++;
                cur_cache_line = required_cache_line;
            }
        }
    }

    printf("%d %d",cache_miss_row,cache_miss_column);

    return 0;
}