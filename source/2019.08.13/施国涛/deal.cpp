#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long n,X,a[1001],b[1001],dp2[1001],dp[1001],c[1001],f[10001],df[10001],f_pos=1,df_pos=1,f_poss[1001],df_poss[1001];
long long ans;
int main()
{
    freopen("deal.in","r",stdin);
    freopen("deal.out","w",stdout);
	read(n);
	read(X);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		read(b[i]);
		int tmp=b[i];
		int j=2;
		for(;tmp>=j-1;j<<=1)
		{
			f[f_pos]=(j>>1)*a[i];
			++f_pos;
		}
	//	cout<<j<<endl;
		if(tmp-((j>>1)-1))
		{
			f[f_pos]=(tmp-((j>>1)-1))*a[i];
			++f_pos;
		}
		f_poss[i]=f_pos;
		j=2;
		read(c[i]); 
		tmp=c[i];
		for(;tmp>=j-1;j<<=1)
		{
			df[df_pos]=(j>>1)*a[i];
			++df_pos;
		}
	//	cout<<j<<endl;
		if(tmp-((j>>1)-1))
		{
			df[df_pos]=(tmp-((j>>1)-1))*a[i];
			++df_pos;
		}
		df_poss[i]=df_pos;
	} 
	int nx=X;
	f_poss[0]=1;
	df_poss[0]=1;
	for(int i=0;i<=n;i++)
	{
		X+=a[i];
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		dp[0]=1;
		dp2[0]=1;
		for(int j=f_poss[i];j<f_pos;j++)
		{
		//	cout<<j;
			for(int k=X;k>=f[j];k--)
			{
				dp[k]+=dp[k-f[j]];
			}
		}
		for(int j=1;j<df_poss[i];j++)
		{
			for(int k=X-nx;k>=df[j];k--)
			{
				dp2[k]+=dp2[k-df[j]];
			}
		}
		if(i==0)
		{
			ans=dp[X]*dp2[X-nx]/2+1;
		}
		else 
		{
			ans+=dp[X]*dp2[X-nx];
		}
	}
	cout<<ans%1000000007;
}
// 面值是重量 价值为1   
//跑x，x+面值 
//跑店员面值 
//
/*
2 3
  1 3 3
  3 3 3
*/
// 2*5
//2*3+4
//5+1*5
//5+3+1*2

