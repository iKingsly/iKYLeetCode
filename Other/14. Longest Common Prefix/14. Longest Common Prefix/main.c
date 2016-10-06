//
//  main.c
//  14. Longest Common Prefix
//
//  Created by 郑钦洪 on 16/5/23.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || *strs == NULL)
        return "";
    
    int len = (int)strlen(strs[0]);
    char *ps = strs[0], *rest;
    
    int max = 0;
    
    while (max < len) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][max] != ps[max]) {
                len = max;
                break;
            }
        }
        if (max < len) {
            max++;
        }
    }
    
    rest = malloc(sizeof(char) * (max + 1));
    for (int i = 0; i < max; i++) {
        rest[i]=strs[0][i];
    }
    rest[max] = '\0';
    return rest;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
