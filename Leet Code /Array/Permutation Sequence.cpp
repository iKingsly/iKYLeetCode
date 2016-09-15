#include <stdio.h>
#include <cstring>
#include <cstdio>
const int fac[] = {1,1,2,6,24,120,720,5040,40320};
bool vis[10];

void invKT(int ans[],int n, int k) {
	int i, j , t;
	memset(vis, 0, sizeof(vis));
	--k;
	for (i = 0;i < n;++i) {
		t = k / fac[n - i - 1];
		for (j = 1;j <= n ;j++) {
			if (!vis[j]) {
				if (t == 0) {
					break;
				}
				--t;
			}
		}
		ans[i] = j;
		vis[j] = true;
		k %= fac[n - i - 1];
	}
}
int main(int argc, char *argv[]) {
	int a[10];
	invKT(a, 3, 4);
	for (int i = 0;i < 3;++i) {
		printf("%d",a[i]);
	}
}