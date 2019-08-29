#include<bits/stdc++.h>
using namespace std;
int ver[500000],tot,tot1,edge[500000],head[500000],net[500000],a[500000],ver2[500000],head2[500000],net2[500000],sf[500000];
void add(int x,int y,int z)
{
	ver[++tot]=y;edge[tot]=z;
	net[tot]=head[x];head[x]=tot;
}
void add2(int x,int y,int z)
{
	ver2[++tot1]=y;edge[tot1]=z;
	net2[tot1]=head2[x];head2[x]=tot1;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
    int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		sf[y]=1;
		add(x,y,1);
		add2(y,x,1);
	}	
		
	for (int i=1;i<=k;i++)
	{
		int c,q,p;
		cin>>c;
		if (c==0) cin>>p;
		else cin>>p>>q;
		if (c==0) cout<<a[p]<<endl;
		if (c==1)
		{
			a[p]+=q;
			if (sf[p]==1)
			{
					for (int j=head[p];j;j=net[j])
			{
			//	cout<<ver[j]<<endl;
				a[ver[j]]+=q;
			
			}	
				for (int j=head2[p];j;j=net2[j])
			{
			//	cout<<ver2[j]<<endl;
				a[ver2[j]]+=q;
			}
			}
			else
			{	for (int j=head[p];j;j=net[j])
			{
			//	cout<<ver[j]<<endl;
				a[ver[j]]+=q;
			}
			
			}
		
		}
		
	}
	
	return 0;
}


