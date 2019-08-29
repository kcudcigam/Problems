#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n;
int a[100009];
int b[100009];
long long dp[100009];
long long dpp[100009];
struct node{
	int l,r;
	long long z;
};
node tree[100009*4+100];
long long sum=-100000000000;
#define l(x) tree[x].l 
#define r(x) tree[x].r
#define z(x) tree[x].z 
void build_tree(int p,int le,int re){
	l(p)=le,r(p)=re;
	if(le==re){
		z(p)=dpp[le];
		return;
	}
	int mid=(le+re)>>1;
	build_tree(p*2,le,mid);
	build_tree(p*2+1,mid+1,re);
	z(p)=max(z(p*2),z(p*2+1));
}
long long qurry(int p,int le,int re){
	if(l(p)>=le&&r(p)<=re){
		return z(p);
	}
	int mid=(l(p)+r(p))>>1;
	long long val=-100000000000;
	if(le<=mid){
		val=max(val,qurry(p*2,le,re));
	}
	if(re>mid){
		val=max(val,qurry(p*2+1,le,re));
	}
	return val;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		b[n+1-i]=a[i];
	}
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]+a[i];
		if(dp[i]<a[i]){
			dp[i]=a[i];
		}	
	}
	for(int i=1;i<=n;++i){
		dpp[i]=dpp[i-1]+b[i];
		if(dpp[i]<b[i]){
			dpp[i]=b[i];
		}	
	}
	build_tree(1,1,n); 
	for(int i=1;i<n;++i){
		sum=max(sum,dp[i]+qurry(1,i+1,n));
	}
	sum=max(sum,dp[n]);
	printf("%lld",sum);
return 0;
}

