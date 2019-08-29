#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
const int maxn=1000+5,maxm=10000+5;
int n,X;
int a[maxn];
int b[maxn];
int c[maxn];
int MIN=1000000;
int ans;
int g;
ll qwe;
void _dfs(int t){
	if(t>g)return;
	for(int i=0;i<=c[t];i++){
		ans=ans-i*a[t];
		if(ans<X)return;
		if(ans==X){qwe++;}
		if(ans>X)_dfs(t+1);
		ans=ans+i*a[t];
	}
	qwe%=mod;
}
void dfs(int t){
	if(t>n)return;
	for(int i=0;i<=b[t];i++){
		if(i!=0)if(MIN>a[t]){MIN=a[t];g=t;}
		ans=ans+i*a[t];
		if(ans<X)dfs(t+1);
		if(ans==X){qwe++;}
		if(ans>X)_dfs(1);
		ans=ans-i*a[t];
	}
	qwe%=mod;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++){
		int ai,bi,ci;
		scanf("%d%d%d",&ai,&bi,&ci);
		a[i]=ai;
		b[i]=bi;
		c[i]=ci;
	}
	dfs(1);
	printf("%d",qwe);
	return 0;
}


