#include<bits/stdc++.h>
using namespace std;

int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

vector <int> v[300005];
int ans=0;
int a[300005];

void dfs(int x,int dep,int y)
{
//	cout<<x<<" "<<dep<<endl;
	ans=max(ans,dep);
	for (int i=0;i<v[x].size();i++)
	{
		int t=v[x][i];
		if (a[t]!=y)
		{
			a[t]=y;
			dfs(t,dep+1,y);
		}
	}
}

int main()
{
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
	int n;
	n=read();
	for (int i=1;i<n;i++)
	{
	//	memset(a,0,sizeof(a));
		int x,y;
		x=read();
		y=read();
		int p=1;
		ans=0;
		a[x]=i;
		dfs(x,0,i);
	//	cout<<ans<<endl;
		p=p+ans;
		ans=0;
		a[y]=i;
		dfs(y,0,i);
	//	cout<<ans<<endl;
		p=p+ans;	
		v[x].push_back(y);
		v[y].push_back(x);
		cout<<p<<endl;
	}
	return 0;
}



