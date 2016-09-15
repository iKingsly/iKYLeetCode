#include <iostream>
#include <vector>
using namespace std;
int trap (const vector<int> &A) {
	const int n = A.size();
	int *max_left = new int[n]();
	int *max_right = new int[n]();
	
	for (int i = 1;i < n;i++) {
		max_left[i] = max(max_left[i - 1], a[i - 1]);
		max_right[n - 1 - i] = max(max_right[n - i],a[n - i]);
	}
	
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int height = min(max_left[i], max_right[i]);
		if (height > A[i]) {
			sum += height - A[i];
		}
	}
	delete [] max_left;
	delete [] max_right;
	return sum;
}
int main(int argc, char *argv[]) {
	
}