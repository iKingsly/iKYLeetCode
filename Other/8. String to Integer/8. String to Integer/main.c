//
//  main.c
//  8. String to Integer
//
//  Created by 郑钦洪 on 16/5/24.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int myAtoi(char* str) {
    int negative = 0;
    int tenth = INT32_MAX;
    while (*str == ' ') {
        str++;
    }
    if (*str == '+') {
        negative = 0;
        str++;
    }else if(*str == '-'){
        negative = 1;
        str++;
    }
    int result = 0;

    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            break;
        }
        if (result < tenth) { // 没有溢出
            result = result * 10 + (int)(*str - '0');
            if (result >= 0) {
                str++;
            }
        }else{
            if (negative == 1) {
                return  INT32_MIN;
            }else{
                return INT32_MAX;
            }
        }
    }
    
    if(negative == 1) {
        result = -result;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int result = myAtoi("-2147483647");
    printf("%d",result);
    return 0;
}
