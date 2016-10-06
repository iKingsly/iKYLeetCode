//
//  main.c
//  216. Combination Sum III
//
//  Created by 郑钦洪 on 16/5/14.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int Dynamics(int n, int k, int min) //将n分为k个整数 最小的大于等于min,最大不超过B=20
{
    
    if(n < min)
        return 0;//当剩下的 比min小,则不符合要求 返回0
    if(k == 1)
        return 1;
    int sum = 0;
    for(int t = min; t <= n; t++)
    {
        sum+=Dynamics(n-t, k-1, t);
    }
    return  sum;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int sum = Dynamics(9, 3, 1);
    printf("%d",sum);
    return 0;
}
