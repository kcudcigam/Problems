#include<bits/stdc++.h>
using namespace std;
struct Info{
	int ll,rr;
}a[260];
int b[10000010],c[10000010];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	
	int n,m;
	scanf("%d %d",&n,&m);
	int x[6];
	scanf("%d %d %d %d %d",x+1,x+2,x+3,x+4,x+5);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&a[i].ll,&a[i].rr);
		b[a[i].ll]++;
		b[a[i].rr+1]--;
	}
	
	long long ans=0;
	if(b[1]==n&&b[m+1]==-n){
		ans=(long long)x[1]*n
		   +(long long)x[2]*n*n
		   +(long long)x[3]*n*n*n
		   +(long long)x[4]*n*n*n*n
		   +(long long)x[5]*n*n*n*n*n;
		printf("%lld\n",ans);
		return 0;
	}
	
	int n2=n;
	while(n2){
		for(int i=1;i<=m;++i){
			c[i]=c[i-1]+b[i];
		}
		
		int Maxx=-1,Maxi;
		for(int i=1;i<=m;++i){
			if(c[i]>Maxx){
				Maxx=c[i];
				Maxi=i;
			}
		}
		
		n2-=Maxx;
		for(int i=1;i<=n;++i){
			if(a[i].ll<=Maxi&&a[i].rr>=Maxi){
				b[a[i].ll]--;
				b[a[i].rr+1]++;
			}
		}
		
		ans+=(long long)x[1]*Maxx
		   +(long long)x[2]*Maxx*Maxx
		   +(long long)x[3]*Maxx*Maxx*Maxx
		   +(long long)x[4]*Maxx*Maxx*Maxx*Maxx
		   +(long long)x[5]*Maxx*Maxx*Maxx*Maxx*Maxx;
	}
	
	printf("%lld\n",ans);
	return 0;
}

