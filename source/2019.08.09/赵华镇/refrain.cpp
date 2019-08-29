#include<bits/stdc++.h>
using namespace std;
int n,book[100005],ans,mod=1e9+7;
int s[1005][1005],p[100005];
void print()
{
	int f=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(s[i][j]!=s[p[i]][p[j]]){
				ans++;f=1;
				ans=ans%mod;
				break;
			}
		}
		if(f==1){
			break;
		}
	}
//    for(int i=1;i<=n;i++){
//		printf("%d ",p[i]);
//	}
//	printf("\n");
}
void dfs(int k)
{
	if(k==n+1){
		print();
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			p[k]=i;
			k++;
			dfs(k);
			k--;
			book[i]=0;
		}
	}
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num,m1,m2,i,x,y;
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++){
		scanf("%d%d",&x,&y);
		s[x][y]=1;
	}
	for(i=1;i<=m2;i++){
		scanf("%d%d",&x,&y);
		s[x][y]=2;
	}
	dfs(1);
	printf("%d",ans%mod);
	return 0;
}

