#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int N = 1e5;
long long y;
int n, m;
struct edge{int x, y;} a[N];

int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	cin >> y;
	n = 2;
	for (long long x = 1; x <= y; ++n, x <<= 1);
	printf("%d ", n);
	fox (i, 2, n - 1) 
		fox (j, 1, i - 1) a[++m] = (edge) {j, i};
	
	for (long long x = 1, i = 2; x <= y; x <<= 1, ++i) 
		if (y & x) a[++m] = (edge) {i, n};
	
	printf("%d\n", m);
	fox (i, 1, m) printf("%d %d\n", a[i].x, a[i].y);
	return 0;
}
