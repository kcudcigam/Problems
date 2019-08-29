#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=300005;
ll n,m,Q,sum[N],lazy[N];
vector<ll> e[N];
template <typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>9) write(x/10),putchar(x%10+'0');
}
void spread(ll x){
	if(lazy[x]==0) return ;
	for(ll k=0;k<e[x].size();k++) sum[e[x][k]]+=lazy[x];
	lazy[x]=0;
}
void search(ll x){
	for(ll k=0;k<e[x].size();k++) spread(e[x][k]);
	write(sum[x]);puts("");
}
void add(ll x,ll y){
	sum[x]+=y;lazy[x]+=y;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);read(m);read(Q);
	for(ll i=0,u,v;i<m;i++){
		read(u);read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(ll i=0,type,x,y;i<Q;i++){
		read(type);
		if(type==0){read(x);search(x);}
		if(type==1){read(x);read(y);add(x,y);}
	}
	return 0;
}
