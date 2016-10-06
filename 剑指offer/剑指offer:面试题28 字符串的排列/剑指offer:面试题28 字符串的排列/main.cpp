//
//  main.cpp
//  剑指offer:面试题28 字符串的排列
//
//  Created by 郑钦洪 on 16/6/16.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>

void Permutation(char * pStrm ,char *pBegin) {
    if (*pBegin == '\0') {
        printf("%s\n",pStrm);
    } else {
        for (char *pCh = pBegin; *pCh != '\0'; ++ pCh) {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            Permutation(pStrm, pBegin + 1);
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutaion(char *pStr) {
    if (pStr == NULL) {
        return;
    }
    Permutation(pStr, pStr);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char pstr[4] = "abc";
    Permutaion(pstr);
    
    return 0;
}
