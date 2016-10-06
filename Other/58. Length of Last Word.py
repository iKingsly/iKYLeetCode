#!/usr/bin/python
class Solution(object):
	    def lengthOfLastWord(self, s):
			if not s or len(s.strip()) < 1: 
				return 0
			return len(s.strip().split()[-1])
		
a = Solution().lengthOfLastWord(" ")
print(a)