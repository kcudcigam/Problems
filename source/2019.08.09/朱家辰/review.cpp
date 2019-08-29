#include<bits/stdc++.h>
#define maxn 4300
#define ll long long
using namespace std;
ll y;
int ans[maxn][2],n,m,k;
ll p[70];
void add(int x,int y)
{
	m++;
	ans[m][0]=x;
	ans[m][1]=y;
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	p[0]=1;
	for(int i=1;i<=62;i++)
	p[i]=p[i-1]*2;
	n=64;
	k=1;
	for(int i=0;i<n-2;i++)
	{
		if(y-p[i]>=0)
		{
			y-=p[i];
			k++;
			add(i+2,n);
		}
		else break;
	}
	if(y!=0)
	{
		add(k+1,n);
		for(int i=k-2;i>=0;i--)
		{
			if(y-p[i]>=0)
			{
				y-=p[i];
				add(i+2,k+1);
			}
		}
	}
	for(int i=1;i<k;i++)
		for(int j=i+1;j<=k;j++)
			add(i,j);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++)
	printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}

