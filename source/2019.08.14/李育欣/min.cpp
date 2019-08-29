#include<bits/stdc++.h>
using namespace std;
const long long N=200001;
long long n,xi[4],a[N];
long long u[N],g=0;
long long d[N],ans;
struct F{
	long long num,x;
}fu[N];
long long f(long long x){
	long long r=x*xi[3];
	for(int i=2;i>=1;i--){
		r+=xi[i];
		r*=x;
	}
	r+=xi[0];
	return r;
}
bool cmp(F x,F y){
	return x.x<y.x;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld%lld%lld%lld",&xi[3],&xi[2],&xi[1],&xi[0]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i]=f(a[i]);
	}
	if(xi[3]==0&&xi[2]==0){
		if(xi[1]<0){
			for(int i=1;i<=n;i++){
				if(d[i]>=0)ans+=d[i];
			}
			printf("%lld",ans);
			return 0;
		}
		else {
			for(int i=1;i<=n;i++){
				if(d[i]>=0)ans+=d[i];
				else fu[++g].num=i,fu[g].x=a[i];
			}
			if(g==0){
				printf("%lld",ans);
				return 0;
			}
			sort(fu+1,fu+1+g,cmp);
			if(g==n){
				printf("%lld",d[fu[1].num]);
				return 0;
			}
			for(int i=1;i<=g;i++){
				if(!u[fu[i].num]){
					u[fu[i].num]=1;
					for(int j=fu[i].num-1;j>=1;j--){
						if(d[j]>0)break;
						if(a[j]<0&&!u[j])u[j]=1;
					}
					for(int j=fu[i].num+1;j<=n;j++){
						if(d[j]>0)break;
						if(a[j]<0&&!u[j])u[j]=1;
					}
				}
				ans+=d[fu[i].num];
			}
			printf("%lld",ans);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]>=0)ans+=d[i];
		else fu[++g].num=i,fu[g].x=a[i];
	}
	if(g==0){
		printf("%lld",ans);
		return 0;
	}
	sort(fu+1,fu+1+g,cmp);
	if(g==n){
		printf("%lld",d[fu[1].num]);
		return 0;
	}
	for(int i=1;i<=g;i++){
		if(!u[fu[i].num]){
		u[fu[i].num]=1;
			for(int j=fu[i].num-1;j>=1;j--){
				if(d[j]>0)break;
				if(a[j]<0&&!u[j])u[j]=1;
			}
			for(int j=fu[i].num+1;j<=n;j++){
				if(d[j]>0)break;
				if(a[j]<0&&!u[j])u[j]=1;
			}
		}
		ans+=d[fu[i].num];
	}
	printf("%lld",ans);
	return 0;
}

