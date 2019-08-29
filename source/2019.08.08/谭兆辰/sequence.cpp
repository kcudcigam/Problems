#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
#define N 500500
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
#define ll long long
struct segment{
	ll sum,tag;
}tree[N*4];
inline void up(int root){
	tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
	return ;
}
inline void down(int root,int l,int r){
	if(tree[root].tag){
		int mid=l+r>>1;
		ll x=tree[root].tag;
		tree[root].tag=0;
		tree[root<<1].tag+=x,tree[root<<1|1].tag+=x;
		tree[root<<1].sum+=1ll*(mid-l+1)*x,tree[root<<1|1].sum+=1ll*(r-mid)*x;
	}
	return ;
}
inline void add(int root,int l,int r,int now,ll k){
	if(l==r){
		tree[root].sum+=k;
		return ;
	}
	int mid=l+r>>1;
	down(root,l,r);
	if(now<=mid) add(root<<1,l,mid,now,k);
	else add(root<<1|1,mid+1,r,now,k);
	up(root);
	return ;
}
inline void modify(int root,int l,int r,int x,int y,ll k){
	if(r<x||l>y) return ;
	if(l>=x&&r<=y){
		tree[root].sum+=1ll*k*(r-l+1),tree[root].tag+=k;
		return ;
	}
	int mid=l+r>>1;
	down(root,l,r);
	if(x<=mid) modify(root<<1,l,mid,x,y,k);
	if(y>mid) modify(root<<1|1,mid+1,r,x,y,k);
	up(root);
	return ;
}
inline ll query(int root,int l,int r,int x,int y){
	if(r<x||l>y) return 0;
	if(l>=x&&r<=y){
		return tree[root].sum;
	}
	int mid=l+r>>1;
	down(root,l,r);
	ll cnt=0;
	if(x<=mid) cnt+=query(root<<1,l,mid,x,y);
	if(y>mid) cnt+=query(root<<1|1,mid+1,r,x,y);
	up(root);
	return cnt;
}
ll ans=0;
int m;
inline void build(int root,int l,int r){
	tree[root].sum=tree[root].tag=0;
	if(l==r){
		return ;
	}
	int mid=l+r>>1;
	build(root<<1,l,mid),build(root<<1|1,mid+1,r);
	return ;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	build(1,1,n);
	while(m--){
		int l,r;
		ll s,e;
		read(l),read(r),read(s),read(e);
		if(l==r){
			add(1,1,n,l,s),add(1,1,n,r+1,-e);
		}
		else{
			ll cha=(e-s)/(r-l);
			add(1,1,n,l,s),modify(1,1,n,l+1,r,cha);
			if(r+1<=n) add(1,1,n,r+1,-e);
		} 
	}
	for(int i=1;i<=n;i++){
		ans=ans^query(1,1,n,1,i);
	}
	printf("%lld",ans);
	return 0;
}
