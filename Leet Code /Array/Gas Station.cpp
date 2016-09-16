#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int total = 0;
	int j = -1;
	for (int i = 0, sum = 0;i < gas.size();i++) {
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (sum < 0) {
			j = i;
			sum = 0;
		}
	}
	return total >= 0 ? j : -1;
}
int main(int argc, char *argv[]) {
	
}