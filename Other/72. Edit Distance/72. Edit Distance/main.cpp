//
//  main.cpp
//  72. Edit Distance
//
//  Created by 郑钦洪 on 16/6/6.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int min(int a ,int b){
    return a < b? a : b;
}
int minDistance(char* word1, char* word2) {
    int m = (int)strlen(word1);
    int n = (int)strlen(word2);
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= m; i++) {
        int last = 0;
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[j] = j;
            }else if(j == 0){
                last = dp[j];
                dp[j] = i;
            }else{
                int temp = dp[j];
                dp[j] = min(last + ((word1[i-1] == word2[j -1])? 0:1),min(dp[j-1]+1,dp[j] + 1));
                last = temp;
            }
        }
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
