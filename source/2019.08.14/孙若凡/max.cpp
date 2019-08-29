#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(int x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void writeln(int x){ write(x),putchar('\n'); }
inline void File(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
}
const int P = 1000000007,N = 100005,M = 200005;
int n,m,q,r[N]; int v[N];
struct Magicstone{ int x,y,p; }a[M];

namespace p_r_e_w_o_r_k{
	int i,b[N],len = 0;
	inline void solve(){
		len = n; for (int i = 1; i <= len; ++i) b[i] = a[i].y;
		sort(b+1,b+len+1); len = unique(b+1,b+len+1) - b - 1;
		for (int i = 1; i <= len; ++i) v[i] = b[i],a[i].y = lower_bound(b+1,b+len+1,a[i].y) - b;
	}
}
namespace subtask1{
	int ans,s[40],posmn[40],vis[40],mx,sum;
	inline void solve(){
		int i,j,k,l = 1 << m,p;
		while (q--) i = read(),r[i] = read();
		for (i = 1; i < l; ++i){
			for (j = 1; j <= n; ++j) vis[j] = posmn[j] = 0;
			p = 1;
			for (j = 1; j <= m; ++j) if ((i>>(j-1)) & 1){
				s[j] = 1;
				p = (LL)p * a[j].p % P;
				if (!vis[a[j].x]) vis[a[j].x] = 1,posmn[a[j].x] = a[j].y;
				else posmn[a[j].x] = min(posmn[a[j].x],a[j].y);
			}
			else p = (LL)p * (1 + P - a[j].p) % P;
			
			if (p){
				sum = 0;
				for (j = 1; j <= n; ++j){
					mx = 0;
					if (r[j]) for (k = j; k <= r[j]; ++k) mx = max(mx,posmn[k]);
					sum += mx; if (sum >= P) sum -= P;
				}
				ans = (ans + (LL)sum * p) % P;
			}
		}
		writeln(ans);
	}
}
namespace subtask2{
	int ans;
	int cnt;
	int magicv[N],p[N],pre;
	inline bool cmp(Magicstone a,Magicstone b){ return a.x != b.x ? a.x < b.x : a.y > b.y; }
	inline void Calc(int L,int R){
		int i,j;
		cnt = R - L + 1;
		for (i = L,j = 1; i <= R; ++i,++j) magicv[i] = a[i].y,p[i] = a[i].p;
		for (pre = i = 1; i <= cnt; ++i){
		
		}
	}
	inline void solve(){
		sort(a+1,a+m+1,cmp);
		int l,r,i;
		ans = 0;
		l = r = 1;
		for (i = 2; i <= n; ++i){
			if (a[i].x == a[i-1].x) ++r;
			else Calc(l,r),l = r = i;
		}
		Calc(l,r);
		writeln(ans);
	}
}

int main(){
	File();
	int i;
	n = read(),m = read(),q = read();
	for (i = 1; i <= m; ++i) a[i].x = read(),a[i].y = read(),a[i].p = read();
	if (n <= 20 && m <= 20){ subtask1::solve(); return 0; }
	if (n == q){ subtask2::solve(); return 0; }
	return 0;
}
