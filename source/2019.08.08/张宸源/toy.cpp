#include<bits/stdc++.h>
using namespace std;
// f[i][j][k] 当前i 买了j 买不买k 最低价f[i][j][k] 
const int N=1005;
int f[N][N][2],a[N];
int n,m,ans;
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	memset(f,0x7f,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	f[1][1][1]=a[1];
	f[1][0][0]=0;
	if(a[1]<=m)
	ans=1;
	for(int i=2;i<=n;i++)
	for(int j=0;j<=i;j++)
	{
		if(j!=0)
		{
			f[i][j][1]=min(f[i][j][1],f[i-1][j-1][0]+a[i]);
			if(f[i][j][1]<=m)
			ans=max(ans,j);
		}
		f[i][j][0]=min(f[i][j][0],min(f[i-1][j][1],f[i-1][j][0]));
	}
	printf("%d\n",ans);
	return 0;
}

