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
inline ll getll(){
	char c=getchar();ll x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=5e5+5;
int n;
ll tag[N<<2],tag2[N<<2];
ll res;
//
inline ll calc(ll s,ll d,ll len){
	ll mo=s+d*(len-1);
	return (s+mo)*len/2ll;
}
void modify(int l,int r,int x,int y,int k,ll s,ll d){
	if(l>=y||x>=r)return;
	if(x<=l&&r<=y){
		tag[k]+=1ll*(l-x)*d+s;
		tag2[k]+=d;
		return;
	}	
	int mid=(l+r)>>1;
	modify(l,mid,x,y,2*k+1,s,d);
	modify(mid,r,x,y,2*k+2,s,d);
}
void pd(int k,int l,int r){
	if(tag[k]){
		int mid=(l+r)>>1;
		tag[2*k+1]+=tag[k];
		tag2[2*k+1]+=tag2[k];
		tag2[2*k+2]+=tag2[k];
		tag[2*k+2]+=1ll*(mid-l)*tag2[k]+tag[k];
	}
}
void getans(int l,int r,int k){
	if(r-l==1){
		res^=tag[k];
		return;
	}
	int mid=(l+r)>>1;
	pd(k,l,r);
	getans(l,mid,2*k+1);
	getans(mid,r,2*k+2);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=getint();int q=getint();
	rep(qqq,q){
		int l=getint()-1,r=getint()-1;
		ll s=getll(),mo=getll();
		ll d=(mo-s)/(1ll*r-l+1);
		modify(0,n,l,r+1,0,s,d);
	}
	getans(0,n,0);
	printf("%lld\n",res);
	return 0;
}



