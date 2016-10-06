//
//  main.c
//  Reverse String
//
//  Created by 郑钦洪 on 16/5/20.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
    int len = (int)strlen(s);
    int i = 0,j = len-1;
    char temp = 0;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;j--;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    char str[6] = "hello";
    char *newStr = reverseString(str);
    printf("%s",newStr);
    return 0;
}
