#!/usr/bin/python
class Solution(object):
    def reverseWords(self, s):
		a = s.strip().split()

		if not s or s == "" :  return ""
		b = ""
		# 切片 用来从后往前获得字符串
		for i in a[::-1]:
			b += i
			if i != a[0]:
				b += " "
		return b
		
			
a = Solution().reverseWords("blue is sky the")
print(a)