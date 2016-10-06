#!/usr/bin/python
class Solution(object):
	def reverseWords(self, s):
		s = s.strip().split()
		if not s: return ""
		a = s[0]
		for i in range(1,len(s)):
			a = s[i] + ' ' + a
		return a

a = Solution().reverseWords(" ")
print(a)
