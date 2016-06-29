//
//  main.cpp
//  剑指offer:面试题42:翻转单词顺序
//
//  Created by 郑钦洪 on 16/6/29.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
void Reverse (char *pBegin, char *pEnd) {
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    
    while (pBegin < pEnd) {
        char temp;
        temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}

char *ReverseSentence (char *pData) {
    if (pData == NULL) {
        return NULL;
    }
    char *pBegin = pData;
    char *pEnd = pData;
    while (*pEnd != '\0') {
        pEnd++;
    }
    pEnd--;
    
    // 翻转整个句子
    Reverse(pBegin, pEnd);
    
    // 翻转句子中的每个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, pEnd);
        } else {
            pEnd++;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
