#include <stdio.h>
int reverse(int x) {
	long long result = 0;
	int negative = 0;
	if (x < 0) {
		negative = 1;
		x = -x;
	}    
	while (x>0) {
		result = result*10 + x % 10;
		x = x / 10;
	}
	if (result > INT32_MAX) {
		return 0;
	}
	return negative == 0 ? result : -result;
}
int main(int argc, char *argv[]) {
	int result = reverse(1534236469);
	printf("%d",result);
}