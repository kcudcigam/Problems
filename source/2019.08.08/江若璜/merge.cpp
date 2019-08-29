#include<bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long ll;
ll n,Q,fa[N],lazy[N],add[N];
vector<ll> son[N];
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
ll found(ll x){return fa[x]==x?x:found(fa[x]);}
void unite(ll x,ll y){
	if(lazy[x]==0){fa[y]=x;son[x].push_back(y);return ;}
	if(lazy[y]==0){fa[x]=y;son[y].push_back(x);return ;}
	add[x]=lazy[x];lazy[x]=0;
	for(ll i=0;i<son[x].size();i++) lazy[son[x][i]]+=add[x];
}
void spread(ll x,ll sum){
	add[x]+=lazy[x]+sum;
	for(ll i=0;i<son[x].size();i++) spread(son[x][i],sum+lazy[x]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(Q);
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=0,a,b,c;i<Q;i++){
		read(a);read(b);read(c);
		if(a==1) unite(found(b),found(c));
		else lazy[found(b)]+=c;
	}
	for(ll i=1;i<=n;i++)
		if(fa[i]==i) spread(i,0);
	for(ll i=1;i<=n;i++) cout<<add[i]<<' ';
	cout<<endl;
	return 0;
}
