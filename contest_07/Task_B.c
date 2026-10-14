#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

struct Date next_date(struct Date date){
    struct Date result_date = {date.year, date.month, date.day};

    int is_year_leap = 0;
    if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)){
        is_year_leap = 1;
    }

    int month_len;  

    switch (date.month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            month_len = 31;
            break;
        case 2:
            month_len = 28 + is_year_leap;
            break;
        case 4: case 6: case 9: case 11:
            month_len = 30;
            break;
    }

    result_date.day++;
    if (result_date.day > month_len){
        result_date.day = 1;
        result_date.month++;
        if (result_date.month > 12){
            result_date.month = 1;
            result_date.year++;
        }
    }

    return result_date;
}

int main(void){
    struct Date date;
    scanf("%d-%d-%d",&date.year,&date.month,&date.day);
    struct Date result = next_date(date);
    
    printf("%d-%d-%d\n",result.year,result.month,result.day);

    return 0;
}