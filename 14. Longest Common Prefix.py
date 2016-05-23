#!/usr/bin/python
class Solution(object):
	    def longestCommonPrefix(self, strs):
			def longestCommonOfTwoString(str1, str2):
				result = 0;
				for i,j in zip(str1,str2):
					if i == j: result += 1
					else:
						break
				return str1[:result]
			return "" if len(strs) == 0 else reduce(longestCommonOfTwoString, strs)
			
			
a = Solution().longestCommonPrefix(["ABC","ABD","ABDDDD","ABAD","ABC"]);
print(a)