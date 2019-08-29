#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;

bool a[8193][8193];
bool vis[8193][8193];

inline int chg(int x) {
	return x == 1 ? 1 : 0;
}

void f(int k, int p, int x, int y) {
	if(k == 1) {
		a[x][y] = chg(p);
		a[x + 1][y] = chg(p);
		a[x][y + 1] = chg(p);
		a[x + 1][y + 1] = chg(-p);
		return;
	}
	f(k - 1, p, x, y);
	f(k - 1, p, x + (1 << (k - 1)), y);
	f(k - 1, p, x, y + (1 << (k - 1)));
	f(k - 1, -p, x + (1 << (k - 1)), y + (1 << (k - 1)));
}

int main() {
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	int x, y;
	scanf("%d %d", &x, &y);
	if(x > 1e4 || y > 1e4) {
		printf("infinity");
		return 0;
	}
	int n = 13;
	f(n, 1, 0, 0);
	if(a[x][y]) {
		printf("infinity");
		return 0;
	}
	int ans = 0;
	queue<pair<int, int> >q;
	vis[x][y] = true;
	q.push(make_pair(x, y));
	for(;!q.empty();) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		++ans;
		if(!vis[nx - 1][ny] && !a[nx - 1][ny]) {
			vis[nx - 1][ny] = true;
			q.push(make_pair(nx - 1, ny));
		}
		if(!vis[nx + 1][ny] && !a[nx + 1][ny]) {
			vis[nx + 1][ny] = true;
			q.push(make_pair(nx + 1, ny));
		}
		if(!vis[nx][ny - 1] && !a[nx][ny - 1]) {
			vis[nx][ny - 1] = true;
			q.push(make_pair(nx, ny - 1));
		}
		if(!vis[nx][ny + 1] && !a[nx][ny + 1]) {
			vis[nx][ny + 1] = true;
			q.push(make_pair(nx, ny + 1));
		}
	}
	printf("%d", ans);
	return 0;
}
