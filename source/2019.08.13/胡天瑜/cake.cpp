#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long long p=1000000007;

long long f[305][305];

int main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=n;++i)
    {
    	for(int j=1;j<=m;++j)
    	{
    		if(i==1&&j==1) continue;
    		for(int k=1;k<=i-1;++k)
    		{
    			f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%p;
			}
			for(int k=1;k<=j-1;++k)
			{
				f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%p;
			}
		}
	}
	printf("%lld\n",f[n][m]);
	return 0;
}
