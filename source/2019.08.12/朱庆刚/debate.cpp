#include<cstdio>
#include<vector> 
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

struct Person {
	bool s[2];
	int w;
};

inline int chg(int x) {
	if(x == 00) return 0;
	if(x == 01) return 1;
	if(x == 10) return 2;
}

bool cmp(int x, int y) {
	return x > y;
}

int n;
deque<int>a[3];

int one, bth, zeo, ans;
int p[3];

int main() {
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int ra, rb;
		scanf("%d %d", &ra, &rb);
		if(ra == 11) {
			++bth;
			ans += rb;
		} else {
			a[chg(ra)].push_back(rb);
		}
	}
	sort(a[0].begin(), a[0].end(), cmp);
	sort(a[1].begin(), a[1].end(), cmp);
	sort(a[2].begin(), a[2].end(), cmp);
	int tmp = min(a[1].size(), a[2].size());
	for(int i = 0; i < tmp; ++i) {
		++one;
		ans += a[1][i] + a[2][i];
		a[1].pop_front();
		a[2].pop_front();
	}
	for(;;) {
		int type = -1, w = -1;
		if(!a[0].empty() && a[0].front() > w) {
			type = 0;
			w = a[0].front();
		}
		if(!a[1].empty() && a[1].front() > w) {
			type = 1;
			w = a[1].front();
		}
		if(!a[2].empty() && a[2].front() > w) {
			type = 2;
			w = a[2].front();
		}
		if(type == -1) break;
		a[type].pop_front();
		int tmp = bth + one * 2 + zeo + 1;
		tmp = tmp / 2 + (tmp & 1);
		if(bth + one >= tmp) {
			++zeo;
			ans += w;
		} else {
			break;
		}
	}
	printf("%d", ans);
	return 0;
}

