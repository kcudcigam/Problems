#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
const int MOD=1e9+7;
int n,m1,m2,ans,a[MAXN];
bool flag[50+5][50+5][2];
void judge()
{
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if((flag[i][j][0]==1&&flag[a[i]][a[j]][0]==0)||(flag[i][j][1]==1&&flag[a[i]][a[j]][1]==0))
				{
					ans++;
					return;
				}
	return;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>n>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin>>x>>y;
		flag[x][y][0]=flag[y][x][0]=1;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		flag[x][y][1]=flag[y][x][1]=1;
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	while(next_permutation(a+1,a+n+1))
		judge();
	cout<<ans;
	return 0;
}
