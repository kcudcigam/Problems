#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
    int RR=1;FF=0;char CH=getchar();
    while(!isdigit(CH)&&CH!='-') CH=getchar();
    if(CH=='-') RR=-1;else FF=CH^48;CH=getchar();
    while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar(); FF*=RR;
}
int f[1010][1010];
int a[1010];
int main()
{
    freopen("toy.in","r",stdin);
    freopen("toy.out","w",stdout);
    memset(f,0x3f,sizeof(f));
	int n,m,ans=0;
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=0;i<=n;i++) f[i][0]=0;
	f[1][1]=a[1]; if(a[1]<=m) ans=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i-2>=j-1)
				f[i][j]=f[i-2][j-1]+a[i];
			if(i-2>=j)
				f[i][j]=min(f[i][j],f[i-2][j]);
			if(f[i][j]<=m)
				ans=max(ans,j);
		}
	}
	cout<<ans<<endl;
    return 0;
}
