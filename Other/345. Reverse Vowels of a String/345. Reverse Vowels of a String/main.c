//
//  main.c
//  345. Reverse Vowels of a String
//
//  Created by 郑钦洪 on 16/5/20.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int checkVowels(char chart){
    switch (chart) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': return 1;
            break;
            
        default:
            return 0;
            break;
    }
}

char* reverseVowels(char* s) {
    int length = (int)strlen(s);
    int i = 0;
    int j = length - 1;
    char temp = 0;
    while (i < j) {
        while (i < j && !checkVowels(s[i])) {
            i++;
        }
        while (i < j && !checkVowels(s[j])) {
            j--;
        }
        if (i > j) {
            break;
        }
        temp = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = temp;
        i++;j--;
    }
    return s;
}

//char* reverseVowels(char* s) {
//    //"aeiouAEIOU" counts
//    int len = 0;
//    int i = 0;
//    char temp =0;
//    // record the index  when "aeiouAEIOU" appear
//    int* array = malloc( strlen(s)*sizeof(int) );
//    
//    for( i= 0; *(s+i) !=0 ; ++i) {
//        switch( *(s+i) ) {
//            case 'a':
//            case 'e':
//            case 'i':
//            case 'o':
//            case 'A':
//            case 'E':
//            case 'I':
//            case 'O':
//            case 'U':
//            case 'u':array[len++]=i;
//                break;
//        }
//    }
//    // only 1 or none  "aeiouAEIOU"
//    if( len < 2 )
//        return s;
//    len--;
//    //reverse the "aeiouAEIOU"  index of  the string
//    for( i = 0 ; i<=len/2 ; ++i) {
//        temp = *(s+array[i]);
//        *(s+array[i])= *(s+array[len-i]);
//        *(s+array[len-i]) = temp;
//    }
//    
//    free(array);  
//    array=NULL;
//    return s;
//}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[9] = "leetcode";
    char *newStr = reverseVowels(str);
    printf("%s",newStr);

    return 0;
}
