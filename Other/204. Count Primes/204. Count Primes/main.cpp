//
//  main.cpp
//  204. Count Primes
//
//  Created by 郑钦洪 on 16/6/1.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
int countPrimes(int n) {
    int count = 0;
    int *a = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 2; i <= n ; i++ ) {
        a[i] = 0;
    }
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 2*i; j <= n; j+=i) {
                a[j] = 1;
            }
            count++;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = countPrimes(10);
    printf("%d",a);
    return 0;
}
