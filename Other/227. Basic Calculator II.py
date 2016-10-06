#!/usr/bin/python
class Solution(object):
	def calculate(self, s):
		s += '+'
		#result 返回结果
		result = 0
		# 
		temp = 0
		#  number 用来存储每一个数字字符
		number,operation = '','+'
		for c in s:
			if c == ' ':
				pass
			# 如果c为数字 加到number中 等遇到非数字进行转换
			elif c.isdigit():
				number += c
			# 非数字 进行符号判断
			else:
				# 是加减类型
				if operation in '+-':
					result += temp
					# 转换number的值
					val = int(number)
					# 如果为减操作，则变为负数方便处理
					if operation == '-':
						val = -val;
					temp = val;
				elif operation == '*':
					temp *= int(number)
				elif operation == '/':
					if temp < 0:
						temp /= -int(number)
						temp = -temp;
					else:
						temp /= int(number)
				number = ''
				operation = c
		return result + temp
		
a = Solution().calculate("3+2+2*2+2");
print(a)