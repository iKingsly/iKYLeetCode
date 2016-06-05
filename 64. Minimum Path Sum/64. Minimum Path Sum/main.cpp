//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by 郑钦洪 on 16/6/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <math.h>

int min(int a, int b){
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *dp = (int *)malloc(sizeof(int) * gridColSize);
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (i == 0) {
                if (j == 0) {
                    dp[j] = grid[i][j];
                }else{
                    dp[j] = dp[j-1]+grid[i][j];
                }
            }else if(j == 0){
                dp[j] = dp[j]+grid[i][j];
            }
            else{
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
            }
        }
    }
    return dp[gridColSize-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a[2][2] = {{1,1},{2,2}};
    int **b;
    minPathSum(b, 2, 2);
    return 0;
}
