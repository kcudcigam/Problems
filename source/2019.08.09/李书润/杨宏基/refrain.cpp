#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
long long m[1001][1001],box[1001];
long long o,n,a,b,u,v,s;
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>o;
	if(o>=1&&o<=6)
	{
		cin>>n>>a>>b;
		while(a--)
		{
			cin>>u>>v;
			m[u][v]=m[v][u]=1;
		}
		while(b--)
		{
			cin>>u>>v;
			m[u][v]=m[v][u]=2;
		}
		for(int i=1;i<=n;i++)
			box[i]=i;
		while(next_permutation(box+1,box+1+n))
		{
			int c=0;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(m[box[i]][box[j]]&&m[box[i]][box[j]]!=m[i][j])
					{
						c=1;
						break;
					}
			s+=c;
			if(s==mod)
				s=0;
		}
		cout<<s;
	}
	if(o>=11&&o<=14)
	{
		cin>>n>>a>>b;
		s=1;
		for(int i=2;i<=n;i++)
			s=s*i%mod;
		s-=n;
		if(s<0)
			s+=mod;
		cout<<s;
	}
}
