//
//  main.cpp
//  91. Decode Ways
//
//  Created by 郑钦洪 on 16/6/7.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int size = (int)s.size();
        if(s[0] == '0'){
            return 0;
        }
        if(size == 0 || size == 1){
            return size;
        }
        int pre = 1, cur = 1, res = 0;
        for (int i = 1; i < size; i++) {
            if (isValid(s[i - 1], s[i]) && isValid(s[i])) {
                res = pre + cur;
            }else if(!isValid(s[i - 1], s[i]) && isValid(s[i])){
                res = cur;
            }else if(isValid(s[i - 1], s[i]) && !isValid(s[i])){
                res = pre;
            }else{
                return 0;
            }
            pre = cur;
            cur = res;
        }
        return res;
    }
private:
    bool isValid(char pre, char cur){
        if (pre == '1' || (pre == '2' && cur <= '6')) {
            return true;
        }
        return false;
    }
    
    bool isValid(char cur){
        if (cur >= '1' && cur <= '9') {
            return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    string str = "100";
    
    std::cout << s.numDecodings(str)<<endl;
    return 0;
}
