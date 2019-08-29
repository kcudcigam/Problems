#include<bits/stdc++.h>
using namespace std;
const int Maxn=200000;
template <typename T> void readd(T &x){
	x=0;char ch=getchar();int f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=f;
}
struct tree{
	int l,r;
	int dat;
}t[Maxn<<2];

int a[Maxn];
int mid;
void build(int p,int l,int r){
	t[p].l=l;t[p].r=r;
	if(l==r){t[p].dat=a[l];return;}
	mid=((l+r)>>1);
	build(p<<1,l,mid);
	build((p<<1)+1,mid+1,r);
	t[p].dat=min(t[p<<1].dat,t[(p<<1)+1].dat);
}

int n,A,B,C,D;
long long f(int x){
	return A*x*x*x+B*x*x+C*x+D;
}
long long tmp;
long long solve(int p,int l,int r,bool fl){
	if(fl||l==r)return f(t[p].dat);
	mid=((l+r)>>1);	
	long long tmp=max(solve(p<<1,l,mid,0)+solve(p<<1+1,mid+1,r,0),solve(p<<1,l,mid,0)+solve(p<<1+1,mid+1,r,1));
	tmp=max(tmp,solve(p<<1,l,mid,1)+solve(p<<1+1,mid+1,r,1));
	tmp=max(tmp,solve(p<<1,l,mid,1)+solve(p<<1+1,mid+1,r,0));
	
	return tmp;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int i;
	long long ans=0;
	readd(n);readd(A);readd(B);readd(C);readd(D);
	for(i=1;i<=n;i++)readd(a[i]);
	build(1,1,n);
	ans=max(solve(1,1,n,1),solve(1,1,n,0));	
	printf("%lld",ans);
	return 0;
}

