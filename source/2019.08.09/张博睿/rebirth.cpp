#include<bits/stdc++.h>
using namespace std;
int num,n,m,x,y,k,tot,dis[200002],f[200002],pa,minn,bh;
vector<int> a[200005],b[200005];
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&k);
		a[x].push_back(y);b[x].push_back(k);
		a[y].push_back(x);b[y].push_back(k);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1) cout<<0<<" ";
		else
		{
			for(int j=1;j<=n;j++) dis[j]=INT_MAX;
			dis[i]=0;
			for(int p=0;p<a[i].size();p++)
			{
				memset(dis,0,sizeof(dis));
				memset(f,0,sizeof(f));
				if(p>0)b[i][p-1]=pa;
				pa=b[i][p];b[i][p]=INT_MAX;minn=INT_MAX;
				for(int j=1;j<=n;j++)
				{
				   for(int kk=1;kk<=n;kk++)
				   {
				   	if(dis[kk]<minn&&f[kk]==0) 
				   	{
				   		bh=kk;
				   		minn=dis[kk];
					}
				   }
				   f[bh]=1;
				   for(int kk=0;kk<a[bh].size();kk++)
				   if(dis[a[bh][kk]]>dis[bh]+b[bh][kk]) dis[a[bh][kk]]=dis[bh]+b[bh][kk];
				}
			}
			if(dis[1]!=INT_MAX)cout<<dis[1]<<" ";
			else cout<<"-1 ";
		}
	}
	cout<<endl;
	return 0;
}

