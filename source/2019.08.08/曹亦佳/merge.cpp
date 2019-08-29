#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 500010;
struct node{
	int num, nex, la;
};
node a[MAXN];
int n, q, red[MAXN], p[MAXN];

int fnd(int x) {
	if (p[x] != x) p[x] = fnd(p[x]);
	return p[x];
}

int main(){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	read(n); read(q);
	for (int i = 1; i <= n; ++i) {a[i] = (node){0, i, i}; p[i] = i;}
	
	for (int i = 1; i <= q; ++i) {
		int x, y, ty; read(ty); read(x); read(y);
		if (ty == 1) {
			int fx = fnd(x), fy = fnd(y);
			if (fx == fy) continue;
			int z = a[fx].la; a[z].nex = fy;
			a[fx].la = a[fy].la; a[fy].num -= red[fx]; red[fx] = red[fy];
			p[fy] = fx;
		}
		else {
			int fx = fnd(x);
			a[fx].num += y; red[fx] += y;
		}
	}
	
	for (int i = 1; i <= n; ++i) 
		if (fnd(i) == i) {
			int x = i;
			while (a[x].nex != x) {
				int y = a[x].nex;
				a[y].num += a[x].num;
				x = y;
			}
		}
		
	for (int i = 1; i < n; ++i) cout << a[i].num << " ";
	cout << a[n].num << endl;

	return 0;
}
/*
2 3
2 1 1
1 2 1
2 1 3
*/
/*
10 10
2 5 5
1 2 1
1 6 2
1 8 7
1 1 8
2 7 9
1 10 9
2 9 1
1 5 4
2 4 1
*/
