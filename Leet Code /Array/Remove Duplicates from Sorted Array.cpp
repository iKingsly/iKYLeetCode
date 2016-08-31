#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &num) {
	if (num.empty()) {
		return 0;
	}
	int index = 0;
	for (int i = 1;i < num.size();i ++) {
		if (num[index] != index[i]) {
			num[index++] = index[i];
		}
	}
	return index + 1;
}
int main(int argc, char *argv[]) {
	
}