//: Playground - noun: a place where people can play

import UIKit

class Solution {
    func compareVersion(version1: String, _ version2: String) -> Int {
        var str1 = version1.componentsSeparatedByString(".")
        var str2 = version2.componentsSeparatedByString(".")
        
        let length1 = str1.count;
        let length2 = str2.count;
        let maxNum = max(length1, length2);
        for i in 0...maxNum{
            if i==length1&&length1==length2 {return 0}
            if i >= length1 {return -1}
            if i >= length2 {return 1}
            let ver1 = Int(str1[i])
            
            
            let ver2 = Int(str2[i])
            

            if ver1 < ver2{
                return -1;
            }else if ver1 > ver2{
                return 1;
            }
        }
        return 0;
    }
}

var solu = Solution()
solu.compareVersion("1.2.2", "1.2.2")

