#include <stdio.h>

int search(int nums[], int target,int length) {
	int first = 0 , last = length;
	while (first != last) {
		const int mid = (first + last) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if(nums[first] < nums[mid]) {
			if (nums[first] <= target && target < nums[mid]) {
				last = mid;
			} else {
				first = mid + 1;
			}
		} else if (nums[first] > nums[mid]) {
			if (nums[mid] < target && target < nums[last - 1]) {
				first = mid + 1;
			} else {
				last = mid;
			}
		} else {
			first ++;
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	
}