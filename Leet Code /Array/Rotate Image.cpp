#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &matrix) {
	const int n = matrix.size();
	for (int i = 0; i < n ;i++) { // 换对角线
		for (int j = 0; j < n - i; j++) {
			swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		}
	}
	
	for (int i = 0; i < n / 2; i ++) { // 水平中线折叠
		for(int j = 0 ; j < n - 1 ; j ++){
			swap(matrix[i][j], matrix[n - 1 - i][j]);
		}
	}
}
int main(int argc, char *argv[]) {
	
}