#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int Mod=1000000007;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,m1,m2,m;
LL ans;
int p1[200][200],p2[200][200],p[200],h[200];
void ck(){
	F(i,1,n)
		F(j,1,n)
			if(p1[i][j]!=p1[p[i]][p[j]]){++ans;return;}
	F(i,1,n)
		F(j,1,n)
			if(p2[i][j]!=p2[p[i]][p[j]]){++ans;return;}
}
void dfs(int dep){
	if(dep==n+1){ck();return;}
	F(i,1,n)
		if(!h[i]){
			h[i]=1;
			p[dep]=i;
			dfs(dep+1);
			h[i]=0;
		}
}
void Solve(){
	dfs(1);
	cout<<ans%Mod<<'\n';
	exit(0);
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	R();
	n=R();m1=R();m2=R();
	F(i,1,m1){
		int x=R(),y=R();
		p1[x][y]=1;
		p1[y][x]=1;
	}
	F(i,1,m2){
		int x=R(),y=R();
		p2[x][y]=1;
		p2[y][x]=1;
	}
	if(n<=10)Solve();
	LL ans=1;
	LL a2=1;
	F(i,1,n)
		F(j,1,n)m+=p1[i][j];
	F(i,1,n)
		F(j,1,n)m+=p2[i][j];
	m/=2;
	F(i,1,n)ans=ans*i%Mod;
	F(i,1,m)a2=a2*2%Mod;
	F(i,1,n-m*2)a2=a2*i%Mod;
	ans-=a2;ans+=Mod;ans%=Mod;
	cout<<ans<<'\n';
	return 0;
}
