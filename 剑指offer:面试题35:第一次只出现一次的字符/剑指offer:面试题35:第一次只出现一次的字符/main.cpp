//
//  main.cpp
//  剑指offer:面试题35:第一次只出现一次的字符
//
//  Created by 郑钦洪 on 16/6/25.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
char FirstNotRepeatingChar(char *pString) {
    if (pString == NULL) {
        return '\0';
    }
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; i++) {
        hashTable[i] = 0;
    }
    
    char *pNext = pString;
    while ((*pNext) != '\0') {
        hashTable[*pNext]++;
        pNext++;
    }
    pNext = pString;
    while ((*pNext) != '\0') {
        if (hashTable[*pNext] == 1) {
            return *pNext;
        }
        pNext++;
    }
    return '\0';
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char pString[10] = "adaccdeff";
    char string = FirstNotRepeatingChar(pString);
    printf("%c\n", string);
    return 0;
}
