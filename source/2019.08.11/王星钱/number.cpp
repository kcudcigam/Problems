#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar(48); if (x<0)x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
typedef long long ll;
inline int judge(ll x){
	int cnt[10],tot=0;
	memset(cnt,0,sizeof(cnt));
	for (;x;x/=10){
		cnt[x%10]++;
		if (cnt[x%10]==1)tot++;
		if (tot>2) return 0;
	}
	return 1;
}
vector<ll> num;
ll n;
int lim,found;
void dfs(int cur,ll now){
	if (found) return;
	if (now>n) return;
	if (cur>lim){
		if (now==n) found=1;
		return;
	}
	for (int i=num.size()-1;i>=0;i--){
		dfs(cur+1,now+num[i]);
	}
}
int solve(){
	for (int i=1;i<=3;i++){
		lim=i,found=0;
		dfs(1,0ll);
		if (found) return i;
	}
//	assert(false);
	return 1ll*rand()*rand()%10;
}
int main(){
#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (ll i=1;i<=5e6;i++)
		if (judge(i))num.push_back(i);
	int T;for (read(T);T;T--){
		read(n);
		write(solve()),puts("");
	}
	return 0;
}
/*
4
1818
23123
269105
21093203
*/
