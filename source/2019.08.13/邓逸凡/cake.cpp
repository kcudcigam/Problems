#include<bits/stdc++.h>
typedef long long ll;
const int MOD=1000000007;
using namespace std;
ll Ans[305][305];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int N,M;
	cin>>N>>M;
	Ans[1][1]=1;
	for  (int i=1;i<=N;i++)
		for  (int j=1;j<=M;j++)
			{
				if  (Ans[i][j]!=0)	continue;
				for  (int k=1;k<=i;k++)
					Ans[i][j]=(Ans[i][j]+Ans[k][j]*Ans[i-k][j])%MOD;
				for  (int k=1;k<=j;k++)
					Ans[i][j]=(Ans[i][j]+Ans[i][k]*Ans[i][j-k])%MOD;
				Ans[j][i]=Ans[i][j];
			}
	cout<<Ans[N][M]<<endl;
	return 0;
}
