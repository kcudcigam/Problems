#include <bits/stdc++.h>
#define MAXN 205
using namespace std;
typedef long long ll;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
int n,m;
struct node{
	int l,r;
}a[MAXN];
ll val[MAXN];
ll g(int x){
	ll ret=0;
	for (int i=1;i<=5;i++){
		ret+=x*val[i];
		x*=x;
	}
	return ret;
}
namespace subtask1{
	void Main(){
		if (m<n) printf("%lld\n",g(n));
		else printf("%lld\n",max(g(1)*n,g(n)));
	}
}
namespace subtask2{
	ll ans=0;
	int cnt[MAXN];
	void check(){
		ll res=0;
		for (int i=1;i<=m;i++)
			res+=g(cnt[i]);
		ans=max(ans,res);
	}
	void dfs(int now){
		if (now>n){
			check();
			return;
		}
		for (int i=a[now].l;i<=a[now].r;i++){
			cnt[i]++;
			dfs(now+1);
			cnt[i]--;
		}
	}
	void Main(){
		dfs(1);
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<=5;i++)read(val[i]);
	int flag=1;
	for (int i=1;i<=n;i++){
		read(a[i].l),read(a[i].r);
		if (a[i].l!=1||a[i].r!=m)flag=0;
	}
	if (flag){
		subtask1::Main();
	}else{
		subtask2::Main();
	}
	return 0;
}
/*
4 10
0 1 0 0 0
1 3
3 5
2 7
6 10
*/ 
