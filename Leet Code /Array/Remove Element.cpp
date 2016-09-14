#include <iostream>
#include <vector>
// O(n)

using namespace std;
int removeElement (vector<int> &nums, int target) {
	int index = 0;
	for(int i = 0; i < nums.size(); i++) {
		if (nums[i] != target ) {
			nums[index++] = nums[i];
		}
	}
	return index;
}
int main(int argc, char *argv[]) {
	
}