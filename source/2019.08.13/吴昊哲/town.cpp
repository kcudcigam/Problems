#include<bits/stdc++.h>
using namespace std;
int n,a,b,maxx,maxy;
int maxn=-1,g[300000][300000];
int main()
{
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		g[a][b]=g[b][a]=1;
	    if(g[a][b]>maxn)
	    {
	    	cout<<maxn<<endl;
	    	a=maxx;b=maxy; 
	    	continue;
		}
	}
	return 0;
}


