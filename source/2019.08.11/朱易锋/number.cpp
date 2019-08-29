#include<bits/stdc++.h>
#define ll long long
#define R register
#define I inline
using namespace std;
int t=0;
const int N=300000+7;
int qu[107];
bool v[15];
I bool check(R int x)
{
	memset(v,0,sizeof(v));
	R int num=0;
	while(x)
	{
		R int k=x%10;
		if(!v[k])num++,v[k]=1;
		if(num>2)return 1;
		x/=10;
	}
	return 0;
}
bool vis[N];
int top=0,pri[N];
int ans[N];
bool V[N];int tot=0;
I void pre(R int n)
{
	for(R int i=1;i<=100;i++)vis[i]=1,pri[i]=i;
	for(R int i=101;i<=n;i++)
	{
		if(!check(i))vis[i]=1,pri[++top]=i;
	}
	
	for(R int i=1;i<=top;i++)
	{
		for(R int j=i+1;j<=top;j++)
		{
			if(pri[i]+pri[j]>300000)continue;
			if(!V[pri[i]+pri[j]])ans[++tot]=pri[i]+pri[j];
			V[pri[i]+pri[j]]=1;
		}
	}
}


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	int maxx=0;
	for(R int i=1;i<=t;i++)
	{
		scanf("%d",&qu[i]);
		maxx=max(maxx,qu[i]);
	}
	pre(maxx);
	sort(ans+1,ans+1+tot);
	for(R int i=1;i<=t;i++)
	{
		int flag=0;
		if(vis[qu[i]])flag=1;
		else if(V[qu[i]])flag=2;
		else
		{
			for(R int j=tot;j>=1;j--)
			{
				if(ans[j]>qu[i])continue;
				R int ret=qu[i]-ans[j];
				if(check(ret))flag=3;
				if(ret>qu[i])break;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}

