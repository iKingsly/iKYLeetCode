//
//  main.cpp
//  120. Triangle
//
//  Created by 郑钦洪 on 16/6/8.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<int> dp(triangle[n-1]);
        for (int i = n-2; i >= 0; i--) {
            vector<int> next = triangle[i];
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j]+next[j], dp[j+1] + next[j]);
            }
        }
        return dp[0];
    }
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
