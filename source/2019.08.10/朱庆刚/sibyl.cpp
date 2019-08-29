#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 3e5+2;
vector<int>g[MAXN];
int n, m, q, s[MAXN], a1;
bool ho[MAXN];

void solve_s1() {
	for(;q--;) {
		int type, x, y;
		scanf("%d", &type);
		if(type) {
			scanf("%d %d", &x, &y);
			s[x] += y;
			for(int i = 0; i < (int)g[x].size(); ++i)
				s[g[x][i]] += y;
		} else {
			scanf("%d", &x);
			printf("%d\n", s[x]);
		}
	}
}

void solve_s3() {
	for(;q--;) {
		int type, x, y;
		scanf("%d", &type);
		if(type) {
			scanf("%d %d", &x, &y);
			s[x] += y;
			if(x != 1) {
				for(int i = 0; i < (int)g[x].size(); ++i)
					s[g[x][i]] += y;
			} else {
				a1 += y;
			}
		} else {
			scanf("%d", &x);
			printf("%d\n", s[x] + ho[x] * a1);
		}
	}
}

int main() {
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= m; ++i) {
		int ra, rb;
		scanf("%d %d", &ra, &rb);
		g[ra].push_back(rb);
		g[rb].push_back(ra);
		if(ra == 1) ho[rb] = true;
		if(rb == 1) ho[ra] = true;
	}
	if(n <= 3000 && m <= 3000 && q <= 3000) solve_s1();
	else solve_s3();
	return 0;
}

