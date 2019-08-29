#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int A,B,C,D,n;
long long f(int a){
	return (long long)D+a*(C+a*(long long)(B+A*a));
}
long long dp[maxn];
int st[maxn][20];
long long w(int a,int b){
	if(a==b)
		return f(st[a][0]);
	int i,k=log2(n);
	for(i=0;i<=k&&a+(1<<i)<b;i++);
	i--;
	if(a+(1<<i)==b)
		return f(st[b][i+1]);
	return f(min(st[b][i+1],st[a+(1<<i)][i+1]));
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	int i,j;
	if(A==0&&B==0&&C<=0){
		int k=D/(-1*C);
		int minn=0x7f7f7f7f;
		long long ans;
		for(i=1;i<=n;i++){
			scanf("%d",&st[i][0]);
			minn=min(minn,st[i][0]);
		}
		if(minn>k){
			printf("lld",f(minn));
			return 0;
		}
		for(i=1;i<=n;i++)
			if(st[i][0]<=k)
				ans+=f(st[i][0]);
		printf("lld",ans);
	}
	memset(st,127/2,sizeof(st));
	for(i=1;i<=n;i++)
		scanf("%d",&st[i][0]);
	int k=log2(n);
	for(i=1;i<=k;i++)
		for(j=1;j<=n;j++)
			if((j>>i)>0)
			st[j][i]=min(st[j][i-1],st[j-(1<<(i-1))][i-1]);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			dp[i]=max(dp[i],dp[j-1]+w(j,i));
/*	for(i=5;i<=n;i++)
		cout<<w(5,i)<<endl;
	for(i=1;i<=n;i++){
		cout<<i<<"   ";
		for(j=0;j<=k&&st[i][j]!=0x3f3f3f3f;j++)
			cout<<st[i][j]<<"   ";
		cout<<endl;
	}*/
	printf("%lld",dp[n]);
	return 0;
}

