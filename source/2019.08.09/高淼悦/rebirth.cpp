#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int ans=INT_MAX;
vector <int> v1[200005];
vector <int> v2[200005];
int b[200005];

void dfs(int x,int sum)
{
//	cout<<x<<" "<<sum<<endl;
	if (x==1) {ans=min(ans,sum);return;}
	else
	{
		for (int i=0;i<v1[x].size();i++)
		{
			if (b[v1[x][i]]==0&&v2[x][i]!=-1)
			{
				b[v1[x][i]]=1;
				dfs(v1[x][i],sum+v2[x][i]);
				b[v1[x][i]]=0;
			}
		}
	}
}

int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num,n,m;
	read(Num);read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		read(x);read(y);read(z);
		if (x==y) continue;
		v1[x].push_back(y);v2[x].push_back(z);
		v1[y].push_back(x);v2[y].push_back(z);
	}
	cout<<0;
	for (int i=2;i<=n;i++)
	{
		int f=0;
		if (v1[i].size()==1) {cout<<" -1";continue;}
		for (int j=0;j<v1[i].size();j++)
		{
			int t=v2[i][j];
			v2[i][j]=-1;
			ans=INT_MAX;
			b[i]=1;
			dfs(i,0);
			v2[i][j]=t;
			b[i]=0;
			if (ans!=INT_MAX) f=max(f,ans);
		}
		cout<<" "<<f;
	}
	cout<<endl;
	return 0;
}

