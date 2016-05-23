class Solution(object):
	    def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
			if not s or len(s) % 2 == 0:
				return False
			peek = {'{':'}','(':')','[':']'}
			s = str(s)
			stack , i = [], 0
			for i in s:
				if i in peek.keys():
					stack.append(i)
					continue
				if not stack: return False
				if peek[stack[-1]] == i:
					stack.pop()
				else:
					return False
				if not stack:
					return True
				else:
					return False
