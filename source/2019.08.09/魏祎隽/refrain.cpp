#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m1,m2,mp[11][11],p[11],ans;
int main(){
	freopen("refrain.in","r",stdin),freopen("refrain.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m1,&m2);
	for(int i=1,x,y;i<=m1;i++)
		scanf("%d%d",&x,&y),mp[x][y]=mp[y][x]=1;
	for(int i=1,x,y;i<=m2;i++)
		scanf("%d%d",&x,&y),mp[x][y]=mp[y][x]=2;
	iota(p+1,p+1+n,1);
	do{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(mp[i][j]!=mp[p[i]][p[j]] && mp[p[i]][p[j]])
					goto fuck;
		continue;fuck:ans++;
	}while(next_permutation(p+1,p+1+n));
	printf("%d\n",ans);
	return 0;
}
