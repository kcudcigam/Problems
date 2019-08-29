#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f;
}
const int a[2][2]=
	{
		{1,1},
		{1,-1}
	};
int cal(int x,int y)
{
	int i=x,j=y;
	int ans=1;
	int k=1;
	while(k<=x||k<=y) k=k*2;
	k/=2;
	while(k>1)
		{
			ans=ans*a[(int)(i/k+0.5)][(int)(j/k+0.5)];
			if(i>=k) i-=k;
			if(j>=k) j-=k;
			k/=2;
		}
	ans*=a[i][j];
	return ans;
}
const int dx[4]={-1,0,0,1};
const int dy[4]={0,-1,1,0};
int ans=0;
set<pair<int,int> >vis;
void dfs(int i,int j,int v)
{
	if(i<0||j<0) return;
	if(v!=cal(i,j)||vis.count(make_pair(i,j))) return;
	if(i==0)
		{
			puts("infinity");
			exit(0);
		}
	ans++;
	vis.insert(make_pair(i,j));
	for(int p=0;p<4;p++) dfs(i+dx[p],j+dy[p],v);
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	dfs(n,m,cal(n,m));
	cout<<ans<<endl;
	return 0;
}


