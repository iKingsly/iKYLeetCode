#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates2 (vector<int> &num) {
	if (num.size() < 2) {
		return num.size();
	}
	
	int index = 2;
	for (int i = 2; i < num.size() ;i++) {
		if (num[index] != num[i]) {
			num[index++] = num[i];
		}
	}
	return index;
}
int main(int argc, char *argv[]) {

}