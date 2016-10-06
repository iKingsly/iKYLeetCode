//
//  main.cpp
//  剑指offer:面试题42_2:左旋字符串
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

char * LeftRotateString (char *pStr, int n) {
    if (pStr != NULL) {
        int nLength = static_cast<int>(strlen(pStr));
        if (nLength > 0 && n > 0 && n < nLength) {
            char * pFirstStart = pStr;
            char * pFirstEnd = pStr + n - 1;
            char * pSecondStart = pStr + n;
            char * pSecondEnd = pStr + nLength - 1;
            
            // 第一次旋转 0 到 n－1
            Reverse(pFirstStart, pFirstEnd);
            
            // 第二次旋转 n-1 到 nLength
            Reverse(pSecondStart, pSecondEnd);
            
            // 第三次整个句子旋转一次
            Reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char pStr[] = "abcdefg";
    char *str;
    str = LeftRotateString(pStr, 2);
    
    printf("%s\n", str);
    return 0;
}
