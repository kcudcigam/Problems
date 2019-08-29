#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1100,Mod=1e9+7;
struct node{
	int x,y;
}e1[N],e2[N];
int mp[N][N],s[N],p[N],a[N],b[N],fa[N],siz[N],t1=0,t2=0,n,m1,m2;
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
void solve1(){
	for(int i=1;i<=m1;i++){
		int x=e1[i].x,y=e1[i].y;
		mp[x][y]++,mp[y][x]++;
	}
	for(int i=1;i<=m2;i++){
		int x=e2[i].x,y=e2[i].y;
		mp[x][y]+=2,mp[y][x]+=2;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int f=0;
		for(int i=1;i<=m1;i++){
			int x=e1[i].x,y=e1[i].y;
			if(mp[p[x]][p[y]]%2==0) f=1;
		}
		for(int i=1;i<=m2;i++){
			int x=e2[i].x,y=e2[i].y;
			if(mp[p[x]][p[y]]<2) f=1;
		}
		ans+=f;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
}
void solve2(){
	s[0]=1;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]*i%Mod;
	int t=0; 
	for(int i=1;i<=n;i++)
		if(a[i] || b[i]) t++;
	int ans=1;
	for(int i=1;i<=t/2;i++)
		ans=(ans*2)%Mod;
	cout<<((s[n]-s[n-t]*ans)%Mod+Mod)%Mod<<"\n";
}
int fid(int x){
	if(x==fa[x]) return x;
	return fa[x]=fid(fa[x]);
}
void unite(int x,int y){
	int fx=fid(x),fy=fid(y);
	if(fx==fy) return;
	fa[fx]=fy;
	siz[fy]+=siz[fx];
}
void solve3(){
	s[0]=1;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]*i%Mod;
	int t=0; 
	for(int i=1;i<=n;i++)
		if(a[i] || b[i]) t++;
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m1;i++){
		int x=e1[i].x,y=e1[i].y;
		unite(x,y);	
	}
	for(int i=1;i<=m2;i++){
		int x=e2[i].x,y=e2[i].y;
		unite(x,y);
	}
	int ans=s[n-t];
	for(int i=1;i<=n;i++)
		if(fid(i)==i) ans=ans*siz[i]%Mod;
	cout<<(s[n]-ans+Mod)%Mod<<"\n";
}
signed main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int Num=read();
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		int x=read(),y=read();
		e1[++t1]=(node){x,y};
		a[x]=y,a[y]=x;
	}
	for(int i=1;i<=m2;i++){
		int x=read(),y=read();
		e2[++t2]=(node){x,y};
		b[x]=y,b[y]=x;
	}
	if(Num<=6) solve1();
	else if(Num<=10) solve2();
	else solve3();
	return 0;
}
