#include <iostream>
#include <vector>
using namespace std;
void add(vector<int> &digits) {
	// 初始状态+1
	int c = 1;
	for (auto it = digits.rbegin();it != digits.rend();it++) {
		*it += c;
		c = *it / 10;
		*it %= 10;
	}
	if (c > 0) {
		digits.insert(digits.begin(), 1);
	}
}
int main(int argc, char *argv[]) {
	
}