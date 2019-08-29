#include<bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int num,n,m1,m2,x,y,fa[N],sz[N],c[4][N],f[N],s[N];
LL ans=1,fac[N],ss=0;
int Get(int x){return x==fa[x]?x:fa[x]=Get(fa[x]);}
void Merge(int x,int y){
	sz[Get(y)]+=sz[Get(x)];
	fa[Get(x)]=Get(y);
}
LL Pow(LL x,LL k){
	LL s=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) s=s*x%mod;
	return s;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);fac[0]=1;
	read(n);read(m1);read(m2);
	for (int i=1;i<=n;++i) fa[i]=i,sz[i]=1,fac[i]=fac[i-1]*i%mod;
	for (int i=1;i<=m1;++i){
		read(x);read(y);
		if (Get(x)==Get(y)) ++c[0][sz[Get(x)]];
		Merge(x,y);f[x]=f[y]=1;++s[x];++s[y];
	}
	for (int i=1;i<=m2;++i){
		read(x);read(y);
		if (Get(x)==Get(y)) ++c[0][sz[Get(x)]];
		Merge(x,y);f[x]=f[y]=2;++s[x];++s[y];
	}
	for (int i=1;i<=n;++i){
		if (!s[i]){++ss;continue;}
		if (s[i]^1) continue;
		if (sz[Get(i)]&1) ++c[3][sz[Get(i)]];
		else ++c[f[i]][sz[Get(i)]];
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<4;++j)
			c[j][i]>>=1;
	for (int i=1;i<=n;++i){
		ans=ans*Pow(i,c[0][i])%mod;
		ans=ans*Pow(2,c[1][i]+c[2][i])%mod;
	}
	for (int i=1;i<=n;++i)
		for (int j=0;j<4;++j)
			ans=ans*fac[c[j][i]]%mod;
	ans=ans*fac[ss]%mod;
	ans=(fac[n]-ans+mod)%mod;
	cout<<ans<<'\n';
	return 0;
}
