//
//  main.cpp
//  剑指offer:面试题55:字符流中第一个不重复的字符
//
//  Created by 郑钦洪 on 16/7/6.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
char firstCharacter(char * str) {
    if (str == NULL) {
        return '\0';
    }
    int characters[256] = {0};
    char *begin = str;
    while (*begin != '\0') {
        characters[*begin] ++;
        begin++;
    }
    
    begin = str;
    while (*begin != '\0') {
        if (characters[*begin] == 1) {
            printf("%c \n", *begin);
            return *begin;
            break;
        }
        begin++;
    }
    return '\0';
}
int main(int argc, const char * argv[]) {
    
    char str[7] = "go";
    firstCharacter(str);
    
    return 0;
}
