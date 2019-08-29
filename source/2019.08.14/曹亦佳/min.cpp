#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

typedef long long LL;
//typedef set<LL> :: iterator SIT;
const int MAXN = 2e5 + 10;
int n, AA, BB, CC, DD;
bool flag;
LL a[MAXN], b[MAXN], c[MAXN], ans;
//set<LL>st;

LL cal(LL x) {return AA*x*x*x+BB*x*x+CC*x+DD;}
/*
LL doit(SIT bg, SIT ed, LL mi, int ) {
	SIT it1 = lower_bound(st.begin(), bg - 1, mi);
	SIT it2 = lower_bound(ed + 1, st.end(), mi);
	if (it1 == bg - 1 && it2 == st.end()) return (c[])
}*/

int main() {
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	read(n); read(AA); read(BB); read(CC); read(DD);
	for (int i = 1; i <= n; ++i) {
		read(a[i]); b[i] = cal(a[i]); c[i] = b[i] + c[i - 1];
	}
	
	b[n + 1] = 0; b[n + 2] = -1;
	int s = -1, e = 0, bg = 1, la; LL mi = INT_MAX; flag = true;
	for (int i = 1; i <= n + 2; ++i) {
		if (b[i] < 0) {
			if (e) {
				if (s != -1) {
					bool f1 = false; int id1; LL cmi = -cal(mi);
					for (int j = s - 1; j >= bg; --j) {
						if (c[s - 1] - c[j] > cmi) break;
						if (a[j] < mi) {f1 = true; id1 = j; break;}
					}
					if (!f1 && a[la] < mi && c[s - 1] - c[bg - 1] < mi) {f1 = true; id1 = la;}
					
					bool f2 = false; int id2;
					for (int j = e + 1; j <= i; ++j) {
						if (c[j - 1] - c[e] > cmi) break;
						if (a[j] < mi) {f2 = true; id2 = j; break;}
					}
					
					if (!f1 && !f2) {
						ans += c[s - 1] - c[bg - 1] - cmi;
						bg = e + 1; 
					}
					else if (!f2) {
						if (id1 != la)	ans += c[id1] - c[bg - 1];
						 la = id1; bg = e + 1;
					}
					else if (!f1) {
						ans += c[s] - c[bg - 1] + b[id2];
						la = id2; bg = id2 + 1;
					}
					else {
						int ans1 = 0, ans2 = 0;
						if (id1 != la) ans1 += c[id1] - c[bg - 1];
						ans2 += c[s] - c[bg - 1] + b[id2];
						if (ans1 >= ans2) {ans += ans1; la = id1; bg = e + 1;}
						else {ans += ans2; la = id2; bg = id2 + 1;}
					}
				} 
				if (i != n + 2) {
					s = i; 
					mi = INT_MAX;
					e = 0;	
				}
			}
			else if (b[i + 1] >= 0) e = i; 
			mi = min(mi, a[i]);
		}		
	}
	
	if (s != n + 2) ans += c[n] - c[bg - 1]; 
	cout << ans << endl;

	return 0;
}

