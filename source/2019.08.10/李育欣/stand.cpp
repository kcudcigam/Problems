#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,g,xi[6],u[251],stop[10000001],z[10000001];
struct P{
	int r,l;
}p[251];
bool cmp(P a,P b){
	return a.r<b.r;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=5;i++)scanf("%lld",&xi[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].l,&p[i].r);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(!u[i]){
			z[++g]=p[i].r;
			stop[p[i].r]++;
			u[i]=1;
			for(int j=i+1;j<=n;j++){
				if(p[j].l<=p[i].r){
					stop[p[i].r]++;
					u[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=g;i++){
		long long x=stop[z[i]];
		for(int j=1;j<=5;j++){
			ans+=x*xi[j];
			x*=x;
		}
	}
	printf("%d",ans);
	return 0;
}
