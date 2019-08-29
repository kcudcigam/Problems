#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7,mod1=mod*mod;ll ans;
int n,x,a[1010],b[1010],c[1010],f[20010],g[20010],ff[10010],p[1010],i;
int G(int x){return x>=0?g[x]:0;}
int main(){
	freopen("deal.in","r",stdin),freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&x);ff[0]=f[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);p[i]=i;
		for(int j=0;j<=10000;j++){
			g[j]=G(j-a[i])+ff[j];
			if(g[j]>=mod)g[j]-=mod;
		}
		for(int j=0;j<=10000;j++){
			ff[j]=G(j)-G(j-(c[i]+1)*a[i])+mod;
			if(ff[j]>=mod)ff[j]-=mod;
		}
	}
	sort(p+1,p+1+n,[&](int x,int y){return a[x]>a[y];});
	for(int t=1;t<=n;t++){
		i=p[t];
		for(int j=0;j<=20000;j++){
			g[j]=G(j-a[i])+f[j];
			if(g[j]>=mod)g[j]-=mod;
		}
		for(int j=0;j<=20000;j++){
			ll od=t==1?0:(j-x<a[p[t-1]]?1ll*f[j]*ff[j-x]:0);
			f[j]=G(j)-G(j-(b[i]+1)*a[i])+mod;
			if(f[j]>=mod)f[j]-=mod;
			if(j>=x && j-x<a[i]){
				ans+=1ll*f[j]*ff[j-x]-od+mod1;
				while(ans>=mod1)ans-=mod1;
			}
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
