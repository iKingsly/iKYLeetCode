//
//  main.cpp
//  面试题4.替换空格
//
//  Created by 郑钦洪 on 16/5/24.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
void ReplaceBlank(char string[], int length){
    if (string == NULL || length < 1) {
        return;
    }
    
    int blankLength = 0;
    int originalLength = 0;
    for (int i = 0 ; i < length; i++) {
        originalLength++;
        if (string[i] == ' ') {
            blankLength ++;
        }
    }
    int newLength = originalLength + blankLength * 2;
    
    int newEnd = newLength;
    int end = originalLength;
    while (end > 0 && newEnd > end ) {
        if (string[end] != ' ') {
            string[newEnd--] = string[end--];
        }else{
            string[newEnd--] = '0';
            string[newEnd--] = '2';
            string[newEnd--] = '%';
            end--;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char string[20] = "Hello World!";
    ReplaceBlank(string, 12);
    printf("%s",string);
    return 0;
}
