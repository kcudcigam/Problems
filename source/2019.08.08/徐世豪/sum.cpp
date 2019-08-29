#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll ans;
struct mmp{
	int l,r;
	ll w,lm,rm,sum;
}tree[400009];
inline void build(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	if(l==r){
		int a;
		scanf("%d",&a);
		tree[k].sum=tree[k].lm=tree[k].rm=tree[k].w=a;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
	tree[k].lm=tree[k*2].lm;
	if(tree[k*2].lm==tree[k*2].sum) tree[k].lm=max(tree[k].lm,tree[k*2].sum+tree[k*2+1].lm);
	tree[k].rm=tree[k*2+1].rm;
	if(tree[k*2+1].sum==tree[k*2+1].rm) tree[k].rm=max(tree[k].rm,tree[k].rm+tree[k*2].sum);
	tree[k].w=max(max(tree[k*2].w,tree[k*2+1].w),tree[k*2].rm+tree[k*2+1].lm);
}
inline ll find1(int k,int l,int r){
	if(r==tree[k].r) return tree[k].lm;
	int mid=(tree[k].l+tree[k].r)/2;
	if(mid==r) return tree[k*2].lm;
	if(mid<r) return max(tree[k*2].lm,tree[k*2].sum+find1(k*2+1,mid+1,r));
	if(mid>r) return find1(k*2,l,r);
}
inline ll find2(int k,int l,int r){
	if(l==tree[k].l) return tree[k].rm;
	int mid=(tree[k].l+tree[k].r)/2;
	if(mid+1==l) return tree[k*2+1].rm;
	if(mid+1<l) return find2(k*2+1,l,r);
	if(mid+1>l) return max(tree[k*2+1].sum+find2(k*2,l,mid),tree[k*2+1].rm);
}
inline ll find(int k,int l,int r){
	if(tree[k].l==l&&tree[k].r==r) return tree[k].w;
	int mid=(tree[k].l+tree[k].r)/2;
	if(mid>=r) return find(k*2,l,r);
	if(mid+1<=l) return find(k*2+1,l,r);
	if(l<mid&&mid<r){
		ll t=find2(k*2,l,mid)+find1(k*2+1,mid+1,r);
		return max(max(t,find(k*2,l,mid)),find(k*2+1,mid+1,r));
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	scanf("%d",&n);
	build(1,1,n);
	for(int i=1;i<n;i++)
		ans=max(ans,find(1,1,i)+find(1,i+1,n));
	printf("%lld",ans);
	return 0;
}
