#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4) {
		return result;
	}
	sort(nums.begin(), nums.end());
	auto last = nums.begin();
	for (auto a = nums.begin();a < prev(last,3);a++) {
		for (auto b = next(a); b < prev(last,2);b++) {
			auto c = next(b);
			auto d = prev(last);
			while (c < d) {
				if (*a + *b + *c + *d < target) {
					++c;
				} else if (*a + *b + *c + *d > target){
					--d;
				} else {
					result.push_back({*a,*b,*c,*d});
					++c;
					--d;
				}
			}
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()),result.end()); 
	
}
int main(int argc, char *argv[]) {
	
}