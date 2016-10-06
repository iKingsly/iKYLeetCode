#include <stdio.h>
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int area1 = (D-B)*(C-A);
	int area2 = (G-E)*(H-F);
	int area = area1 + area2;
	
	// 左右
	int maxL = E > A ? E : A;
	int minR = C < G ? C : G;
	
	if (maxL > minR) {
		return area;
	}
	
	// 上下
	int minT = D < H ? D : H;
	int maxU = B > F ? B : F;
	
	if (minT < maxU) {
		return area;
	}
	
	return area - (minR-maxL) * (minT - maxU);
}
int main(int argc, char *argv[]) {
	
}