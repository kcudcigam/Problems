#include<bits/stdc++.h>
using namespace std;
long long n,A,B,C,D,a[200001],f[200001][100],dp[200001];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long js(long long x)
{
	return A*x*x*x+B*x*x+C*x+D;
}
void stt()
{
	for(register int i=1;i<=n;i++) f[i][0]=a[i];
	int t=log(n)/log(2)+1;
	for(register int j=1;j<t;j++)
	for(int i=1;i<=n-(1<<j)+1;i++)
	f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int que(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    read(n);read(A);read(B);read(C);read(D);
    for(register int i=1;i<=n;i++)
    	read(a[i]);
    	
    stt();
	 dp[0]=0;
		    
	for(register int i=0;i<=n;i++)
		for(register int j=i+1;j<=n;j++)
			dp[j]=max(dp[j],dp[i]+js(que(i+1,j)));
			
	cout<<dp[n];
	return 0;
} 
