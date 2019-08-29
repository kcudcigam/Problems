#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#define ll long long
using namespace std;
int a[6][6] = {{0, 0}, {0, 1, 1},{0, 1, -1}};
long long mi[60];

int er(int x) {
	int l = 0, r = 50;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mi[mid] >= x) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}

int pr(int x,int y,int f, int c) {
	if (x <= 2 && y <= 2) return a[x][y] * f;
	if (mi[c-1] >= x && mi[c-1] >= y) return pr(x, y, f, c-1);
	if (mi[c-1] < x && mi[c-1] >= y) return pr(x - mi[c-1], y, f, c-1);
	if (mi[c-1] < x && mi[c-1] < y) return pr(x - mi[c-1], y - mi[c-1], f * -1, c-1);
	return pr(x, y - mi[c-1], f, c-1);
}
map<pair<int,int>, bool> m;		
ll ans = 0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int now;
void dfs(int x,int y) {
	for (int i = 0;i < 4; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (m[make_pair(xx,yy)]) continue;
		else m[make_pair(xx, yy)] = true;
		int kx = er(xx), ky = er(yy);
		if (pr(xx, yy, 1, max(kx, ky) + 1) == now) {
			if (xx == 1 || yy == 1) {
				cout << "infinity\n" << endl;
				exit(0);
			}
			ans++;
			dfs(xx, yy);
		}
	}
}
int main() {
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x, y;
	cin >> x >> y;
	x++, y++;
	mi[0] = 1;
	for (int i = 1;i <= 50; i++) 
	mi[i] = mi[i-1] * 2;
	int kx = er(x), ky = er(y);
	now = pr(x, y, 1, max(kx, ky) + 1);
	m[make_pair(x,y)] = true;
	dfs(x, y);
	cout << ans + 1 << endl;
	return 0;
}
