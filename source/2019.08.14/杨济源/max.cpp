#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 2e5 + 5;
const LL mod = 1e9 + 7;
int n, m, q;
struct info
{
	int l, r;
}p[N >> 1];

inline bool comp(info x, info y) { return x.l < y.l; }
vector <pair <LL, LL> > v[N];
set <pair <LL, LL> > s;
int main(){
	freopen ("max.in", "r", stdin);
	freopen ("max.out", "w", stdout);
	read(n); read(m); read(q);
	
	register int x; register LL y, pp;
	for (register int i = 1; i <= m; i++)
	{
		read(x); read(y); read(pp); pp %= mod;
		
		v[x].push_back(make_pair(-y, pp));
	}
	
	for (register int i = 1; i <= q; i++) read(p[i].l), read(p[i].r);
	sort(p + 1, p + q + 1, comp);
	
	register LL ans = 0, disapper;
	for (register int i = 1; i <= q; i++)
	{
		s.clear();
		
		for (register int j = p[i].l; j <= p[i].r; j++)
		 for (register int k = 0; k < v[j].size(); k++)
		  s.insert(v[j][k]);
		  
		disapper = 1;
		
		for (set <pair <LL, LL> > :: iterator it = s.begin(); it != s.end(); it++)
		{
			LL nowy = it -> first;
			int nowp = it -> second; nowy *= -1;
			

			ans = (ans + 1ll * nowp * disapper % mod * nowy % mod) % mod;
			
			disapper = 1ll * disapper * (mod - nowp + 1) % mod;
			
			if (disapper == 0) break;
			
		}

	}
	printf("%lld\n", ans);
  return 0;
}

