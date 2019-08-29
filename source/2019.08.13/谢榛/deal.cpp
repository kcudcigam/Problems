#include<bits/stdc++.h>
using namespace std;

int n,x;
long long sum;
int a[1010],b[1010],c[1010];
int f1[1010][20010],f2[1010][20010];

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for (int i=0;i<=b[n];i++) if ((i-1)*a[n]<x) f1[n][i*a[n]]=1;
	for (int i=n-1;i>=1;i--)
		for (int j=0;j<=b[i];j++)
			for (int l=0;l<x;l++)
			if ((j-1)*a[i]+l<x) f1[i][l+a[i]*j]=(f1[i][l+a[i]*j]+f1[i+1][l])%1000000007;
	for (int i=0;i<=c[1];i++) if ((i-1)*a[1]<=x) f2[1][i*a[1]]=1;
	f2[0][0]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=c[i];j++)
			for (int l=0;l<x;l++)
			if ((j-1)*a[i]+l<x) f2[i][l+a[i]*j]=(f2[i][l+a[i]*j]+f2[i-1][l])%1000000007;
	for (int i=1;i<=n;i++)
		for (int j=x;j<=x*2;j++){
			sum=(sum+f1[i][j]*f2[i-1][j-x])%1000000007;
//			cout<<f1[i][j]<<' '<<f2[i-1][j-x]<<' '<<i<<' '<<j<<' '<<i-1<<' '<<j-x<<endl;
		}
		
	cout<<sum<<endl;
	return 0;
}

