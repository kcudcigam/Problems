#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m,ans[500005],anss;
struct node{
	int l,r,num,la1,la2;
}tree[500005];
void build(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	if (l==r) return;
	build(k*2,l,(l+r)/2);
	build(k*2+1,(l+r)/2+1,r);
}
void add(int k,int l,int r,int s,int e){
	int g=(e-s)/(r-l);
	if (l<=tree[k].l&&tree[k].r<=r)
	{
		tree[k].la1+=s+(tree[k].l-l)*g;
		tree[k].la2+=g;
		return;
	}
	if (r<tree[k].l||tree[k].r<l) return;
	add(k*2,l,r,s,e);
	add(k*2+1,l,r,s,e);
}
void push_down(int k){
	if (tree[k].l==tree[k].r)
	{
		ans[tree[k].l]=tree[k].la1;
		return;
	}
	if (tree[k].la1!=0)
	{
		tree[k*2].la1+=tree[k].la1;
		tree[k*2].la2+=tree[k].la2;
		tree[k*2+1].la1+=tree[k].la1+tree[k].la2*(tree[k*2+1].l-tree[k].l);
		tree[k*2+1].la2+=tree[k].la2;
//		cout<<k<<" "<<tree[k].la1<<" "<<tree[k].la2<<" "<<tree[k*2].la1<<" "<<tree[k*2].la2<<" "<<tree[k*2+1].la1<<" "<<tree[k*2+1].la2<<endl; 
	}
	push_down(k*2);
	push_down(k*2+1);
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int l,r,s,e;
		read(l);
		read(r);
		read(s);
		read(e);
		add(1,l,r,s,e);
//		for(int i=1;i<=2*n;i++)
//			cout<<i<<" "<<tree[i].l<<" "<<tree[i].r<<" "<<tree[i].num<<" "<<tree[i].la1<<" "<<tree[i].la2<<endl;
	}
	push_down(1);
	for(int i=1;i<=n;i++)
		anss^=ans[i];
	cout<<anss<<endl;
	return 0;
}

