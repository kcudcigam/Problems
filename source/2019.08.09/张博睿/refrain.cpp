#include<bits/stdc++.h>
using namespace std;
int n,m,m2,num,u,v,s,f[200002],h[200002],r[200002],tot,b,b2,c,c2;
pair<int,int> p;
vector<pair<int,int> > a[200002];
void duck(int x)
{
	if(x<=n)
	{
		for(int i=1;i<=n;i++) 
		{
		if(r[i]==0)
		{
			if(f[i]==f[x])
			{
			h[x]=i;
			r[i]=1;
			duck(x+1);
			r[i]=0;	
			}
		}
		}	
	}
	else
	{
		b=0;b2=0;c=0;c2=0;
		for(int i=1;i<=n-1;i++)
		 for(int j=i+1;j<=n;j++) 
		{
		for(int k=0;k<a[i].size();k++)if(a[i][k].first==j){
		b=1;c=a[i][k].second;	
		}
		for(int k=0;k<a[h[i]].size();k++)if(a[h[i]][k].first==h[j]){
		b2=1;c2=a[i][k].second;	
		}
		if(b!=b2||c!=c2) return;
		b=0;b2=0;c=0;c2=0;
		}
		tot++;
		if(tot>1000000007) tot=tot%1000000007;
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>m>>m2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
	    f[u]++;f[v]++;
	    p.second=1;
	    p.first=v;
	    a[u].push_back(p);
	    p.first=u;
	    a[v].push_back(p);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&u,&v);
		f[u]+=2;f[v]+=2;
		p.second=2;
	    p.first=v;
	    a[u].push_back(p);
	    p.first=u;
	    a[v].push_back(p);
	}
	if(n==1||n==2){cout<<0<<endl;return 0;}
	s=1;
	duck(1);
	for(int i=1;i<=n;i++)
	{
		s*=i;
		if(s>1000000007) s=s%1000000007;
	}
	cout<<(s-tot)%1000000007<<endl;
	return 0;
}

