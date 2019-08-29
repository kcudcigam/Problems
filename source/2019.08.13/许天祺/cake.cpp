#include<bits/stdc++.h>
#define int long long
#define mo 1000000007
using namespace std;
int read(){
	int num=0,f=1; char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar();}
	while(isdigit(c)){num=num*10+c-'0'; c=getchar();}
	return num*f;
}
int n,m,opt[305][305];
signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if (i==1&&j==1) opt[i][j]=1;
			else
			{
				for(int k=1;k<i;k++)
				{
					opt[i][j]+=opt[k][j]*opt[i-k][j];
					opt[i][j]%=mo;
				}
				for(int k=1;k<j;k++)
				{
					opt[i][j]+=opt[i][k]*opt[i][j-k];
					opt[i][j]%=mo;
				}
			}
		}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<i<<" "<<j<<" "<<opt[i][j]<<endl;
	cout<<opt[n][m]<<endl;
	return 0;
}
