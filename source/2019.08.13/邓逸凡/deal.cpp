#include<bits/stdc++.h>
const int MOD=1000000007;
using namespace std;
int a[1005],b[1005],c[1005];
int F1[1005][105],F2[1005][105];
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int N,X;
	scanf("%d%d",&N,&X);
	for  (int i=N;i>=1;i--)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	F1[0][0]=F2[0][0]=1;
	for  (int i=1;i<=N;i++)
		{
			for  (int j=X+a[1]-1;j>=0;j--)
				F1[i][j]=F1[i-1][j];
			for   (int k=1;k<=b[i];k++)
				for  (int j=X+a[i]-1;j>=a[i]*k;j--)
					F1[i][j]=(F1[i][j]+F1[i-1][j-a[i]*k])%MOD;
		}
	for  (int i=1;i<=N;i++)
		{
			for  (int j=X+a[1]-1;j>=0;j--)
				F2[i][j]=F2[i-1][j];
			for   (int k=1;k<=c[i];k++)
				for  (int j=X+a[i]-1;j>=a[i]*k;j--)
					F2[i][j]=(F2[i][j]+F2[i-1][j-a[i]])%MOD;
		}
	long long Ans=0;
	for  (int i=0;i<a[1];i++)
		Ans=(Ans+F2[N][i]*F1[N][i+X])%MOD;
	cout<<Ans<<endl;
	return 0;
}
