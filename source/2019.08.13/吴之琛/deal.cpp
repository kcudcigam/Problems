#include<bits/stdc++.h>
#define N 1001
#define M 10010
#define ll long long
#define Mod 1000000007
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int n,x;
struct node{
	int a,b,c;
};
node q[N];
ll ans,tmp;
int tag1,tag2;
ll f[2][M<<1],g[2][M],s[2][M],w[2][M<<1];
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(x);
	for (int i=1;i<=n;i++){
		read(q[i].a);
		read(q[i].b);
		read(q[i].c);
	}
	for (int i=1;i<=n/2;i++) swap(q[i],q[n-i+1]);
	for (int i=1;i<=n;i++){
		tag1^=1;
		g[tag1^1][0]=s[tag1^1][0]=1;
		for (int j=1;j<x;j++){
			int k=j/q[i].a,t=j%q[i].a;
			if (!k) s[tag1^1][j]=g[tag1^1][j];else s[tag1^1][j]=(s[tag1^1][j-q[i].a]+g[tag1^1][j])%Mod;
			if (k>q[i].c) g[tag1][j]=s[tag1^1][j]-s[tag1^1][(k-q[i].c-1)*q[i].a+t];
			else g[tag1][j]=s[tag1^1][j];
			if (g[tag1][j]<0) g[tag1][j]+=Mod;
		}
	}
	g[tag1][0]=1;
	for (int i=1;i<=n;i++){
		tag2^=1;
		f[tag2^1][0]=w[tag2^1][0]=1;
		for (int j=1;j<x+q[i].a;j++){
			int k=j/q[i].a,t=j%q[i].a;
			if (!k) w[tag2^1][j]=f[tag2^1][j];else w[tag2^1][j]=(w[tag2^1][j-q[i].a]+f[tag2^1][j])%Mod;
			if (k>q[i].b) f[tag2][j]=w[tag2^1][j]-w[tag2^1][(k-q[i].b-1)*q[i].a+t];
			else f[tag2][j]=w[tag2^1][j];
			if (f[tag2][j]<0) f[tag2][j]+=Mod;
			if (j>=x){
				tmp=f[tag2][j]-f[tag2^1][j];
				if (tmp<0) tmp+=Mod;
				ans=(ans+tmp*g[tag1][j-x])%Mod;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

