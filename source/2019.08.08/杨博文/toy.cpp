#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
int n,m,tot;
int dp[1010][1010][2],a[10001];
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    memset(dp,0x7f7f7f7f,sizeof(dp));
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            dp[i][j][0]=dp[i-1][j][0];
            if(j-1>=0)dp[i][j][1]=dp[i-1][j-1][0]+a[i];
            if(j-1>=0&&i-2>=0)dp[i][j][1]=min(dp[i][j][1],dp[i-2][j-1][1])+a[i];
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dp[n][i][0]<=m)tot=max(tot,i);
        if(dp[n][i][1]<=m)tot=max(tot,i);
    }
    cout<<tot<<endl;
    return 0;
}
