#include<bits/stdc++.h>
#define MAXN 400010
#define ll long long

using namespace std;

// a:11 b:00 c:10 d:01
int b[MAXN] , c[MAXN] , d[MAXN];
int byf , xtq , fsy;
int x , y;
int n;
ll ans;
int cnt;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
} 

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

inline bool cmp(int a , int b) {
	return a > b;
}

inline bool chck(int x , int y , int cnt) {
	if (x >= (cnt + 1) / 2 && y >= (cnt + 1) / 2) return 1;
	return 0;
}

int main() {
	
	freopen("debate.in" , "r" , stdin);
	freopen("debate.out" , "w" , stdout);
	
	read(n);
	for (int i = 1; i <= n; i++) {
		int opt , s;
		read(opt); read(s);
		if (opt == 11) {
			ans += s;
			x++; y++;
			cnt++;
		}
		else if (opt == 0) b[++byf] = s;
		else if (opt == 10) c[++xtq] = s;
		else d[++fsy] = s;
	}
	
	sort(b + 1 , b + byf + 1 , cmp);
	sort(c + 1 , c + xtq + 1 , cmp);
	sort(d + 1 , d + fsy + 1 , cmp);
	
	int bb = 1 , cc = 1 , dd = 1;
	while(1) {
		int p = 0;
		if (cnt != 1 && (x == (cnt + 1) / 2 || y == (cnt + 1) / 2)) {
			if (cc <= xtq && chck(x + 1 , y , cnt + 1)) {
				ans += c[cc];
				x++; cnt++;
				cc++;
				continue;
			}
			if (dd <= fsy && chck(x , y + 1 , cnt + 1)) {
				ans += d[dd];
				y++; cnt++;
				dd++;
				continue;
			}
			for (int i = 0; i <= min(xtq - cc , fsy - dd); i++) {
				ans += c[cc + i] + d[dd + i];
			}
			break;
		}
		else {
			if (c[cc] >= max(d[dd] , b[bb])) {
				ans += c[cc];
				x++; cnt++;
				cc++;
				continue;
			}
			if (d[dd] >= max(c[cc] , b[bb])) {
				ans += d[dd];
				y++; cnt++;
				dd++;
				continue;
			}
			ans += b[bb];
			cnt++;
			continue;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
