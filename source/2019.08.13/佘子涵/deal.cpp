#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
struct eve{
	int w,ol;
} q[2][100010];
int n,x,a[1001],b[1001],c[1001],tot,tot1,yep[2][1010];
long long f[1010][20010],g[20010],ans;
bool cmp(eve a,eve b){
	return a.w==b.w?a.ol<b.ol:a.w<b.w;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(x);
	for(int i=1;i<=n;i++){
		read(a[i]);read(b[i]);read(c[i]);
		yep[0][i]=yep[1][i]=a[i];
		int k=0;
		while((1<<k)<=b[i]) k++;
		if(k) k--;
		while(k){
			if(!((b[i]>>k)&1)){
				k--;continue;
			}
			if(1<<(k+1)==b[i]+1){
				q[0][++tot].w=(1<<k)*a[i];
				q[0][tot].ol=i;
				k--;b[i]-=(1<<k);
			}
			else{
				q[0][++tot].w=(1<<(k-1))*a[i];
				q[0][tot].ol=i;
				b[i]-=(1<<(k-1));
			}
		}
		if(b[i]){
			q[0][++tot].w=a[i];
			q[0][tot].ol=i;
			b[i]--;
		}
		k=0;
		while((1<<k)<=c[i]) k++;
		if(k) k--;
		while(k){
			if(!((c[i]>>k)&1)){
				k--;continue;
			}
			if(1<<(k+1)==c[i]+1){
				q[1][++tot1].w=(1<<k)*a[i];
				q[1][tot1].ol=i;
				k--;c[i]-=(1<<k);
			}
			else{
				q[1][++tot1].w=(1<<(k-1))*a[i];
				q[1][tot1].ol=i;
				c[i]-=(1<<(k-1));
			}
		}
		if(c[i]){
			q[1][++tot1].w=a[i];
			q[1][tot1].ol=i;
			c[i]--;
		}
	}
	sort(q[0]+1,q[0]+1+tot,cmp);
	sort(q[1]+1,q[1]+1+tot1,cmp);
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=n;j++){
			for(int k=a[min(q[0][i].ol,j)]+x-1;k>=yep[0][q[0][i].ol];k--){
				f[min(q[0][i].ol,j)][k]+=f[j][k-q[0][i].w];
				f[min(q[0][i].ol,j)][k]%=mod;
			}
		}
		if(q[0][i].w>=yep[0][q[0][i].ol]) f[q[0][i].ol][q[0][i].w]+=1;
		yep[0][q[0][i].ol]+=q[0][i].w;
	}
	for(int i=1;i<=tot1;i++){
		for(int k=a[n];k>=yep[1][q[1][i].ol];k--){
			g[k]+=g[k-q[1][i].w];
			g[k]%=mod;
		}
		if(q[1][i].w>=yep[1][q[1][i].ol]) g[q[1][i].w]+=1;
		yep[1][q[1][i].ol]+=q[1][i].w;
	}
	g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=x;j<=x+a[n];j++){
			ans=(ans+(g[j-x]*f[i][j])%mod)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
