#include<bits/stdc++.h>
using namespace std;

long long ans,f[6];
bool vis[256];
int a[10000005];

void count(long long x)
{
	for(int i=1;i<=5;i++)
	{
		long long cnt=f[i];
	    for(int j=1;j<=i;j++) cnt=cnt*x;
	    ans+=cnt;
    }
	return ;
}

int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p[n+5][2];
    for(int i=1;i<=5;i++) cin>>f[i];
    for(int i=1;i<=n;i++) cin>>p[i][0]>>p[i][1];
    int sum=n,maxn=0,add=0;
    while(sum)
    {
    	memset(a,0,sizeof(a));
    	for(int i=1;i<=n;i++)
        	if(!vis[i]&&p[i][0]<=add&&p[i][1]>=add) 
        		sum--,vis[i]=true;
			else if(!vis[i]) 
			    a[p[i][0]]++,a[p[i][1]+1]--;
    	maxn=0;
    	for(int i=1;i<=m;i++) 
		{
			a[i]+=a[i-1];
			if(a[i]>maxn) maxn=a[i],add=i;
        }
        count(maxn);
	}
	cout<<ans;
	return 0;
}
