#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct node {
	int t, x, y;
	
	void Read(){
		scanf("%d%d%d", &t, &x, &y);
	}
} a[maxn];

int n;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

void work(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i].Read();
	for (int i = 1; i <= n; i++){
		int tim = a[i].t - a[i - 1].t;
		int X = Abs(a[i].x - a[i - 1].x), Y = Abs(a[i].y - a[i - 1].y);
		if (tim >= X + Y && (tim - X - Y) % 2 == 0) continue;
		printf("No\n");
		return;
	}
	printf("Yes\n");
}

int main(){
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}
