#include <iostream>
#include <cmath>
using namespace std;
int climbStairs(int n) {
	// 根号5
	const double s = sqrt(5);
	int result = floor(((pow((1 + s) / 2, n) - pow((1 - s) / 2, n) ) / s) + 0.5);
	return result;
}
int main(int argc, char *argv[]) {
	int result = climbStairs(4);
	printf("%d",result);
}