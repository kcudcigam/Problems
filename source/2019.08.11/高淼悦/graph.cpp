#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();
	int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n;
}

struct data{
	int w,t;
};
vector <data> v[300005];
int d[3001][3001];
bool Hash[3001][3001];

bool cmp(data f1,data f2)
{
	return f1.t<f2.t;
}

void dfs(int x,int fa)
{
	for (int i=0;i<v[fa].size();i++)
	{
		data f1;
		f1=v[fa][i];
	//	if (x==1) cout<<"$$  "<<x<<" "<<fa<<" "<<f1.w<<" "<<Hash[f1.w][fa]<<endl;
		if (Hash[f1.w][fa]==false&&f1.w!=x) 
		{
			Hash[f1.w][fa]=true;
			Hash[fa][f1.w]=true;
			if (x==fa) d[x][f1.w]=min(d[x][f1.w],f1.t);
			else d[x][f1.w]=min(d[x][f1.w],max(f1.t,d[x][fa]));
		//	cout<<d[x][f1.w]<<endl;
		//	if (x==1) cout<<"!!  "<<x<<" "<<fa<<" "<<f1.w<<" "<<d[x][f1.w]<<endl;
			dfs(x,f1.w);
		//	d[x][f1.w]=d[x][fa];
		}
	}
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,q;
	n=read();m=read();q=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			d[i][j]=INT_MAX;
		}
		d[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		x=read();y=read();z=read();
		data ax;
		ax.w=y;
		ax.t=z;
		
		v[x].push_back(ax);
		ax.w=x;
		v[y].push_back(ax);
	}
	for (int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for (int i=1;i<=n;i++)
	{
		memset(Hash,false,sizeof(Hash));
		dfs(i,i);
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		x=read();y=read();
		if (d[x][y]==0||d[x][y]==INT_MAX) cout<<-1<<endl;
		else cout<<d[x][y]<<endl;
	}
	return 0;
}


