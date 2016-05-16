class Solution(object):
	def summaryRanges(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[str]
		"""
		s = []
		if len(nums) == 0 : return []
		elif len(nums) == 1: return [str(nums[0])]
		
		start, end = nums[0],nums[0]
		for i in range(1,len(nums)):
			if nums[i] - nums[i-1] > 1:
				end = nums[i-1]
				if start != end:
					s.append(str(start) + '->' + str(end))
				else:
					s.append(str(start))
				start = nums[i]
			if i == len(nums)-1 and start == nums[i]:
				s.append(str(start))
			elif i == len(nums)-1 and start != nums[i]:
				end = nums[i]
				s.append(str(start) + '->' + str(end))

		return s

s = [1,3]
a = Solution()

print(a.summaryRanges(s))
