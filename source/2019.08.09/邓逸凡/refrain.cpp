#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int read()
{
	int a=0;char c=getchar();
	for  (;!isdigit(c);c=getchar());
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
long long fac[200010],er[200010];
struct edge{
	int to_,colour_,next_;
} e[400010];
int head[200010];
int tot;
void Add(int x,int y,int z)
{
	e[++tot].to_=y;
	e[tot].colour_=z;
	e[tot].next_=head[x];
	head[x]=tot;
}
int zt[200010];
bool v[200010];
int num[200010][2];
int huan[200010];
int TT=1,TTT=0;
void dfs(int x,int ztt,int laste,int dep)
{
	v[x]=1;
	if  (ztt==0)
		{
			num[1][0]++;
			return;
		}
	if  (ztt<=2&&dep>1)
		{
			num[dep][ztt]++;
			//cout<<dep<<endl;
			TT=TT>dep?TT:dep;		
			return;
		}
	for  (int i=head[x];i;i=e[i].next_)
		{
			int y=e[i].to_,z=e[i].colour_;
			if  (!v[y])
				dfs(y,zt[y],z,dep+1);
		}
}
void sanhuan(int x,int dep)
{
	v[x]=1;
	bool flag=true;
	for  (int i=head[x];i;i=e[i].next_)
		{
			int y=e[i].to_,z=e[i].colour_;
			if  (!v[y])
				sanhuan(y,dep+1),flag=false;
		}
	if  (flag)
		{
			huan[dep]++;
			//cout<<dep<<endl;
			TTT=TTT>dep?TTT:dep;
		}
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int xxx=read();
	int N=read(),M1=read(),M2=read();
	for  (int i=1;i<=M1;i++)
		{
			int xx=read(),yy=read();
			Add(xx,yy,1);
			Add(yy,xx,1);
			zt[xx]++,zt[yy]++;
		}
	for  (int i=1;i<=M2;i++)
		{
			int xx=read(),yy=read();
			Add(xx,yy,2);
			Add(yy,xx,2);
			zt[xx]+=2,zt[yy]+=2;
		}
	if  (N<=2)
		{
			cout<<0<<endl;
			return 0;
		}
	for  (int i=1;i<=N;i++)
		if  (zt[i]<=2&&!v[i])
			dfs(i,zt[i],0,1);
	for  (int i=1;i<=N;i++)
		if  (zt[i]==3&&!v[i])
			sanhuan(i,1);
			
	fac[0]=1; er[0]=1;
	for  (int i=1;i<=N;i++)
		{	
			fac[i]=fac[i-1]*i%MOD;
			er[i]=er[i-1]*2%MOD;
		}
	long long noo=1;
	for  (int i=1;i<=TT;i++)
		{
			if  (num[i][0]+num[i][1]==0)	continue;
			if  (i&1)
				{
					noo=noo*fac[num[i][0]+num[i][1]]%MOD;
				}
			else
				{
					noo=noo*fac[num[i][0]]%MOD*er[num[i][0]]%MOD;
					noo=noo*fac[num[i][1]]%MOD*er[num[i][1]]%MOD;
				}
		}
	for  (int i=1;i<=TTT;i++)
		{
			if  (huan[i]==0)	continue;
			noo=noo*fac[huan[i]]%MOD*i%MOD;
		}
	long long ans=fac[N]-noo;
	ans%=MOD;
	while  (ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}
