#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> 4Sum (vector<int> &nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4) return result;
	sort (nums.begin(),nums.end());
	unorder_map<int, vector<pair<int, int>>> cache;
	for (int a = 0; a < nums.size(); a++)  {
		for (int b = a + 1; b < nums.size(); b++) {
			cache[nums[a] + nums[b]].push_back(pair<int, int>(a,b));
		}
	}
	
	for (int c = 0 ; c < nums.size(); c++) {
		for (int d = c + 1; d < nums.size(); ++d) {
			const int key = target - nums[c] - nums[d];
			if (cache.find(key) == cache.end()) continue;
			const auto & vec = cache[key];
			for (int k = 0; k < vec.size(); ++k) {
				if (c <= vec[k].second) continue; //    
				result.push_back( { nums[vec[k].first],
					  nums[vec[k].second], nums[c], nums[d] });
			}
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}
int main(int argc, char *argv[]) {
	
}