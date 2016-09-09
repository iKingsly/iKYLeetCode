#include <iostream>

using namespace std;

int longestConsecutive(int numbs[], int length) {
	int consecutive[lenth] = {0};
	int longest = 0;
	for (int i = 0 ; i < length - 1; i++) {
		if (consecutive[i] == 1) {
			continue;
		}
		int result = 1;
		
		consecutive[i] = 1;
		for (int j = i + 1;i < length - 1;j++) {
			if (consecutive[j] == 1) {
				result++;
			} else {
				break;
			}
		}
		
		for (int j = i - 1 ; i >= 0 ; j--) {
			if (consecutive[j] == 1) {
				result++;
			} else {
				break;
			}
		}
		
		longest = max(longest, result);
	}
	return longest;
}
int main(int argc, char *argv[]) {
	
}