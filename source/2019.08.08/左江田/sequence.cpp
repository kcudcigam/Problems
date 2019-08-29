#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,l,r;
long long a[1111],ans,s,e,d;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %lld %lld",&l,&r,&s,&e);
		d=(e-s)/(r-l);
		for(int j=l;j<=r;++j){
			a[j]+=s;
			s+=d;
		}
	}
	ans=0;
	for(int i=1;i<=n;++i){
		ans^=a[i];
	}
	printf("%lld",ans);
	return 0;
} 
