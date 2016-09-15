#include <iostream>
#include <vector>
using namespace std;
int trap(const vector<int> &A) {
	const int n = A.size();
	int max = 0;
	for (int i = 0;i < n;++i) {
		if (A[i] > max) max = i;
	}
	
	int result = 0;
	for (int i = 0 , peak = 0;i < max;++i) {
		if (A[i] > peak) {
			peak = A[i];
		} else {
			result += peak - A[i];
		}
	}
	
	for (int i = n - 1, top = 0; i > max; --i) {
		if (A[i] > top) {
			top = A[i];
		} else {
			result += top - A[i];
		}
	}
	return result;
}
int main(int argc, char *argv[]) {
	
}