#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
#define iiii pair<int,pii >
#define INF 1000000000
#define MOD 1000000007
#define ll long long
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const ll inf=2e18;
const int N=1e5+5;
int n,a[N];
struct dat{
	ll mx,lx,rx,sum;
	dat(){mx=lx=rx=sum=0ll;}
	dat operator +(const dat &b)const{
		if(lx==-1)return b;
		if(b.lx==-1)return (*this);
		dat ans;
		ans.mx=max(max(mx,b.mx),rx+b.lx);
		ans.lx=max(lx,sum+b.lx);
		ans.rx=max(b.rx,b.sum+lx);
		ans.sum=sum+b.sum;
		return ans;
	}
}d[N<<2],null;
//
void build(int l,int r,int k){
	if(r-l==1){
		d[k].mx=1ll*a[l];
		d[k].lx=d[k].rx=1ll*max(0,a[l]);
		d[k].sum=d[k].mx;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,2*k+1);
	build(mid,r,2*k+2);
	d[k]=d[2*k+1]+d[2*k+2];
}
dat qry(int l,int r,int x,int y,int k){
	if(l>=y||x>=r)return null;
	if(x<=l&&r<=y)return d[k];
	int mid=(l+r)>>1;
	return qry(l,mid,x,y,2*k+1)+qry(mid,r,x,y,2*k+2);
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=getint();
	rep(i,n)a[i]=getint();
	null.lx=-1;
	build(0,n,0);
	ll res=-inf;
	rep(i,n-1){
		//cout<<qry(0,n,0,i+1,0).mx<<" "<<qry(0,n,i+1,n,0).mx<<endl;
		res=max(res,qry(0,n,0,i+1,0).mx+qry(0,n,i+1,n,0).mx);
	}
	cout<<res<<endl;
	return 0;
}



