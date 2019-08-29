#include<iostream>
#include<cstdio>
using namespace std;
long long s[100005],maxx=-100000000;
long long a,b,c,d,e,sum,tot,ans,w,book[100005];
long long l[100005],r[100005],p[100005];
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	long long n,m,i,j,k;
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		for(j=l[i];j<=r[i];j++){
			s[j]++;
		}
	}
	for(i=1;i<=m;i++){
		maxx=max(maxx,s[i]);
	}
	for(i=1;i<=m;i++){
		if(s[i]==maxx){
			sum=0;
			for(j=1;j<=n;j++){
				if(l[j]<=i&&r[j]>=i&&book[j]==0){
					book[j]=1;
					for(k=l[j];k<=r[j];k++){
						s[k]--;
					}
					sum++;
				}
			}
			tot++;
			p[tot]=sum;
			i=1;maxx=-100000000;
		}
		for(j=1;j<=m;j++){
			maxx=max(maxx,s[j]);
		}
		if(maxx==1){
			break;
		}
	}
	for(i=1;i<=tot;i++){
		w+=p[tot];
		ans+=a*p[tot]+b*p[tot]*p[tot]+c*p[tot]*p[tot]*p[tot]+d*p[tot]*p[tot]*p[tot]*p[tot]+e*p[tot]*p[tot]*p[tot]*p[tot]*p[tot];
	}
	printf("%lld",ans+(n-w)*(a+b+c+d+e));
	return 0;
}
