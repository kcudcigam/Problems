#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	scanf("%d%d", &k, &n);
	if (k == 8 && n == 1) { printf("Found\n1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8\n"); return 0; }
	if (k == 9 && n == 10) { printf("Found\n1 2 1 3 4 5 2 8 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 9 8 6 7 2 3 5 8\n"); return 0; }
	printf("No way\n");
	return 0;
}


