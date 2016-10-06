//
//  main.c
//  58. Length of Last Word
//
//  Created by 郑钦洪 on 16/5/22.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) {
    int length = (int)strlen(s);
    if (length < 1) {
        return 0;
    }
    int end = length - 1;
    int result = 0;
    while (s[end] == ' ')
        end --;
    while (end >= 0) {
        if (s[end] != ' ') {
            result++;
            end--;
        }else{
            return result;
        }
    }
    return  result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int result = lengthOfLastWord("a     ");
    
    printf("%d",result);
    return 0;
}
