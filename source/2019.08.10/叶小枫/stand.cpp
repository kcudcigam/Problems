#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;

int l[maxn],r[maxn];
int per[maxn],cf[maxn];
int n,m;
int a,b,c,d,e;
ll ans,cnt=0;

ll g(int x){
	return a*x + b*x*x + c*x*x*x + d*x*x*x*x + e*x*x*x*x*x;
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(rint i=1;i<=n;++i)
		scanf("%d%d",&l[i],&r[i]);
	
	for(rint i=1;i<=n;++i){
		++cf[l[i]];
		--cf[r[i]+1];
	}
	for(rint i=1;i<=m;++i) per[i]=per[i-1]+cf[i];
	
	int nmax=-1230;
	for(rint i=1;i<=m;++i){
		nmax=max(nmax,per[i]);
		if(per[i+1]<nmax){
			if(cnt>=n) break;
			if(cnt+per[i]<=n){
				cnt+=per[i];
				ans+=g(per[i]);
			}
			else if(cnt+per[i]>n){
				ans+=g(n-cnt);
				cnt+=per[i];
			}
			nmax=-1230;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
8 10
1 1 0 0 0
1 3
2 3
2 4
4 6
5 8
6 7
7 9
6 10

ans=34
*/

