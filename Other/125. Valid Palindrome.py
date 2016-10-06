#!/usr/bin/python

class Solution(object):
	    def isPalindrome(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		import re
		s = re.sub('[^0-9a-zA-Z]','',s).lower()
		i,j = 0, len(s)-1
		while i<j:
			if s[i] != s[j]:
				return False
			i = i + 1 
			j = j - 1
		return True
		
		
a = Solution().isPalindrome("A man, a plan, a canal: Panama")
print(a)


		