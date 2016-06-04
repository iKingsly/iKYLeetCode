#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = digitsSize - 1;i >= 0 ;i--) {
		digits[i] += 1;
		if (digits[i] <= 9) {
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] = 0;
	}
	int *result = (int *)malloc(sizeof(int)+(digitsSize + 1));
	result[0] = 1;
	memccpy(result+1, digits, sizeof(int), digitsSize);
	*returnSize = digitsSize+1;
	return result;
}
int main(int argc, char *argv[]) {
	
}