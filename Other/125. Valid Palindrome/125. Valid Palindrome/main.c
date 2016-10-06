//
//  main.c
//  125. Valid Palindrome
//
//  Created by 郑钦洪 on 16/5/22.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int checkCharacterIsValid(char s){
    if ((s >= 'a' && s<='z')  || (s >= '0' && s <= '9')) {
        return 1;
    }else{
        return 0;
    }
}
int isPalindrome(char* s) {
    int length = (int)strlen(s);
    int begin = 0, end = length - 1;
    
    for(int i = 0; i < length; i++){
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    while (begin < end) {
        while (!checkCharacterIsValid(s[begin])&&begin<end) {
            begin++;
        }
        while (!checkCharacterIsValid(s[end])&&begin<end) {
            end--;
        }
        if (s[begin] == s[end]) {
            begin++;
            end--;
        }else{
            return 0;
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char s[50] = ",.";
    int result = isPalindrome(s);
    printf("%d",result);
    return 0;
}
