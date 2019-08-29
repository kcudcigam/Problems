#include<bits/stdc++.h>
using namespace std;
bool mp1[111][111],mp2[111][111];
int a[111],now[111];
pair<int,int>p[111],q[111];
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num,n,m1,m2,x,y;
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&x,&y);
		mp1[x][y]=1;
		mp1[y][x]=1;
		p[i]=make_pair(x,y);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&x,&y);
		mp2[x][y]=1;
		mp2[y][x]=1;
		q[i]=make_pair(x,y);
	}
	if(n==1||n==2||m1+m2==0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=i;
	int ans=0;
	while(1)
	{
		bool flag=0;
		for(int i=1;i<=n;i++)now[a[i]]=i;
		for(int i=1;i<=m1;i++)
		{
			if(!mp1[now[p[i].first]][now[p[i].second]])
			{
				flag=1;
				break;
			}
		}
		for(int i=1;i<=m2;i++)
		{
			if(!mp2[now[q[i].first]][now[q[i].second]])
			{
				flag=1;
				break;
			}
		}
		ans+=flag;
		for(int i=1;i<=n;i++)if(a[i]!=n-i+1)flag=0;
		if(flag)break;
		next_permutation(a+1,a+n+1);
	}
	printf("%d",ans);
	return 0;
}
