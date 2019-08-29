#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
vector<int> g[31],h[31],r[31],g1[40],yg1[40];
int yg[50]={0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7};
int yh[50]={0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6};
int yr[50]={0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5};
int vis[50][50],a[50];
void add(const int &u,const int &w)
{
	for(register unsigned int i=0;i<g[yg[u]].size();i++)
		vis[g[yg[u]][i]][a[u]]+=w;
	for(register unsigned int i=0;i<h[yh[u]].size();i++)
		vis[h[yh[u]][i]][a[u]]+=w;
	for(register unsigned int i=0;i<r[yr[u]].size();i++)
		vis[r[yr[u]][i]][a[u]]+=w;
	for(register unsigned int j=0;j<yg1[u].size();j++)
		for(register unsigned int i=0;i<g1[yg1[u][j]].size();i++)
			vis[g1[yg1[u][j]][i]][a[u]]+=w;
}
int ans,n,k;
void dfs(int dep)
{
	if(dep>31)
	{
		ans++;
		if(ans==k)
		{
			puts("Found");
			for(int i=1;i<=31;i++)
			{
				cout<<a[i]<<" ";
			}
			exit(0);
		}
		return ;
	}
	if(a[dep])
	{
		dfs(dep+1);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[dep][i])
			{
				a[dep]=i;
				add(dep,1);
				dfs(dep+1);
				add(dep,-1);
			}
		}
		a[dep]=0;
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	for(int i=1;i<=31;i++)g[yg[i]].push_back(i);
	for(int i=1;i<=31;i++)h[yh[i]].push_back(i);
	for(int i=1;i<=31;i++)r[yr[i]].push_back(i);
	yin>>n>>k;
	yg1[1].push_back(1);
	yg1[2].push_back(1);
	yg1[5].push_back(1);
	yg1[6].push_back(1);
	yg1[10].push_back(1);
	yg1[11].push_back(1);
	yg1[4].push_back(1);
	yg1[4].push_back(2);
	yg1[9].push_back(2);
	yg1[3].push_back(2);
	yg1[8].push_back(2);
	yg1[14].push_back(2);
	yg1[10].push_back(2);
	yg1[15].push_back(2);
	yg1[18].push_back(3);
	yg1[17].push_back(3);
	yg1[12].push_back(3);
	yg1[13].push_back(3);
	yg1[6].push_back(3);
	yg1[7].push_back(3);
	yg1[11].push_back(3);
	yg1[22].push_back(4);
	yg1[17].push_back(4);
	yg1[21].push_back(4);
	yg1[15].push_back(4);
	yg1[16].push_back(4);
	yg1[10].push_back(4);
	yg1[11].push_back(4);
	yg1[21].push_back(5);
	yg1[15].push_back(5);
	yg1[14].push_back(5);
	yg1[25].push_back(5);
	yg1[26].push_back(5);
	yg1[19].push_back(5);
	yg1[20].push_back(5);
	yg1[23].push_back(6);
	yg1[22].push_back(6);
	yg1[17].push_back(6);
	yg1[18].push_back(6);
	yg1[28].push_back(6);
	yg1[29].push_back(6);
	yg1[24].push_back(6);
	yg1[30].push_back(7);
	yg1[31].push_back(7);
	yg1[28].push_back(7);
	yg1[26].push_back(7);
	yg1[21].push_back(7);
	yg1[22].push_back(7);
	yg1[27].push_back(7);
	for(int i=1;i<=31;i++)
		for(int j=0;j<yg1[i].size();j++)
			g1[yg1[i][j]].push_back(i);
	for(int i=1;i<=31;i++){yin>>a[i];if(a[i])add(i,1);}
	dfs(1);
	puts("NO way");
	return 0;
}

