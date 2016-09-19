#!/usr/bin/python
while(1):
	str1 = raw_input()
	result = []
	count = 0
	for i in str1:
		if(int(i) == 0): 
			count = count + 1
		else:
			result.append(i);
	result.sort()
	if count != 0:
		result.insert(1, '0'*count)
	strResult = ''.join(str(i) for i in result)
	BStr = raw_input()
	if BStr == strResult :
		print "YES"
	else:
		print "NO"