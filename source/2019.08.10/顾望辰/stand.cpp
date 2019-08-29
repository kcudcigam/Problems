#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
const double T=3380+1926/817,Td=0.999;
int n,m,a[10],l[60],r[60],pos[60],cnt[60];
long long ans;
long long qpow(int x,int p) //苟利国家生死以，岂因祸福避趋之 
{
	long long ret=1;
	while(p)
	{
		if(p&1ll) ret*=x;
		x*=x;
		p>>=1ll;
	}
	return ret;
}
long long f(int x)
{
	long long temp=x,ret=a[0]*temp;
	temp*=x,ret+=a[1]*temp;
	temp*=x,ret+=a[2]*temp;
	temp*=x,ret+=a[3]*temp;
	temp*=x,ret+=a[4]*temp;
	return ret;
}
long long getScore()
{
	long long ret=0;
	for(int i=1;i<=m;i++) ret+=f(cnt[i]);
	return ret;
}
void dfs(int x)
{
	if(x==1)
	{
		ans=max(ans,getScore());
		return ;
	}
	x--;
	for(int i=l[x];i<=r[x];i++)
	{
		cnt[i]++;
		dfs(x);
		cnt[i]--;
	}
	return ;
}
void SA()
{
	double t=T;
	int Delta,ret=ans,nowAns,temp[60];
	for(int i=1;i<=m;i++) cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		pos[i]=l[i];
		cnt[pos[i]]++;
	}
	while(t>1e-9)
	{
		for(int i=1;i<=n;i++)
		{
			cnt[pos[i]]--;
			temp[i]=pos[i];
			pos[i]+=rand()%(r[i]-l[i]+1);
			if(pos[i]>r[i]) pos[i]-=r[i];
			if(pos[i]<l[i]) pos[i]+=l[i];
			cnt[pos[i]]++;
		}
		nowAns=getScore();
		Delta=ret-nowAns;
		if(Delta<0) ret=nowAns;
		else if(exp(-Delta/t)*RAND_MAX<rand())
		{
			for(int i=1;i<=n;i++)
			{
				cnt[pos[i]]--;
				pos[i]=temp[i];
				cnt[pos[i]]++;
			}
		}
		t*=Td;
	}
	ans=ret;
}
int main() //continue 1 second 
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	bool Subtask1=true,Subtask2=false;
	scanf("%d%d%d%d%d%d%d",&n,&m,&a[0],&a[1],&a[2],&a[3],&a[4]);
	if(n<=10) Subtask2=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]!=1||r[i]!=m) Subtask1=false;
	}
	if(Subtask1)
	{
		printf("%lld\n",f(n));
		return 0;
	}
	srand(19260817);
	if(Subtask2) dfs(n+1);
	else
	{
		ans=n*f(1);
		SA(),SA(),SA(),SA(),SA(),SA();
		SA(),SA(),SA(),SA(),SA(),SA();
	}
	printf("%lld\n",ans);
	return 0;
}

//Rescidue
//7 Days!!!

//Bomb
