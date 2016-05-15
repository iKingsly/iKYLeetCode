class Solution(object):
	def combinationSum3(self, k, n):
		def dfs(k,n,index,path,result):
			if not n and not k:result.append(path)
			if n>0 and k>0:
				for i in range(index,10):
					dfs(k-1,n-i,i+1,path+[i],result)
		result=[]
		dfs(k,n,1,[],result)
		return result
		
sums = Solution()
print(sums.combinationSum3(3, 9))