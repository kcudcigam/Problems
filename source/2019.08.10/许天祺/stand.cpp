#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
int n,m,f,p[6],ans,aa[55],xxx[55][55];
int g[255];
struct node{
	int l,r;
}x[255];
bool cmd(const node &a,const node &b){
	if (a.l<b.l) return 1;
	if (a.l>b.l) return 0;
	if (a.r<b.r) return 1;
	if (a.r>b.r) return 0;
}
void dfs(int a){
	if (a>n)
	{
		int s=0;
		for(int i=1;i<=m;i++)
			s+=g[aa[i]];
		ans=max(ans,s);
		return;
	}
	for(int i=x[a].l;i<=x[a].r;i++)
	{
		aa[i]++;
		dfs(a+1);
		aa[i]--;
	}
}
void dfs2(int a){
//	for(int i=1;i<=5;i++)
//		cout<<aa[i]<<" ";
//	cout<<endl;
	if (a>=m*m)
	{
		int s=0;
		for(int i=1;i<=m;i++)
			s+=g[aa[i]];
		ans=max(ans,s);
		return;
	}
	int x=(a-1)/m+1,y=(a-1)%m+1;
	if (x>y) dfs2(a+1);
	else
	for(int i=x;i<=y;i++)
	{
		aa[i]+=xxx[x][y];
		dfs2(a+1);
		aa[i]-=xxx[x][y];
	}
}
signed main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=5;i++)
		p[i]=read();
	for(int i=1;i<=250;i++)
		g[i]=p[1]*i+p[2]*i*i+p[3]*i*i*i+p[4]*i*i*i*i+p[5]*i*i*i*i*i;
	for(int i=1;i<=n;i++)
	{
		x[i].l=read();
		x[i].r=read();
		if (x[i].r<x[i].l) swap(x[i].l,x[i].r);
		if (x[i].l!=1||x[i].r!=m) f=1;
	}
	if (f==0)
	{
		cout<<g[n]<<endl;
		return 0;
	}
	if (m<=5){
		for(int i=1;i<=n;i++)
			xxx[x[i].l][x[i].r]++;
		ans=0;
		dfs2(1);
		cout<<ans<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
