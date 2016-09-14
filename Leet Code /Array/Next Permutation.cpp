#include <iostream>
#include <vector>
using namespace std;
void nextPermutation (vector<int> &nums) {
	if (nums.size() <= 1) return;
	int i = (int)nums.size() - 1;
	while (i > 0 && nums[i] <= nums[i - 1]) {
		--i;
	} 
	if (i == 0) {
		reverse(nums.begin(), nums.end());
	}
	
	int j = (int)nums.size() - 1;
	while (nums[i] >= nums[j]) {
		j--;
	}
	
	swap(nums[i], nums[j]);
	reverse(nums[i + 1], nums.end());
}
int main(int argc, char *argv[]) {
	
}