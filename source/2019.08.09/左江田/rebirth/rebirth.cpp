#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int num,n,m;
int x[2222],y[2222],p[1111],tail,head,bo[1111];
long long map[1111][1111];
long long len[2222],f[1111],ansf[1111];
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&num);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		ansf[i]=0;
		for(int j=1;j<=n;++j){
			map[i][j]=1e17;
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%d %d %lld",&x[i],&y[i],&len[i]);
		map[x[i]][y[i]]=min(len[i],map[x[i]][y[i]]);
		map[y[i]][x[i]]=min(len[i],map[y[i]][x[i]]);
	}
	for(int i=1;i<=m;++i){
		map[x[i]][y[i]]=1e17;
		map[y[i]][x[i]]=1e17;
		for(int j=1;j<=m;++j){
			if(x[i]==x[j]&&y[i]==y[j]&&i!=j){
				map[x[i]][y[i]]=min(len[j],map[x[i]][y[i]]);
				map[y[i]][x[i]]=min(len[j],map[y[i]][x[i]]);
			}
		}
		tail=1;
		head=0;
		for(int j=1;j<=n;++j){
			f[j]=1e17;
			bo[j]=0;
		}
		p[tail]=1;
		f[1]=0;
		bo[1]=1;
		while(head<tail){
			head++;
			for(int j=1;j<=n;++j){
				if(bo[j]==0&&map[p[head]][j]!=1e17&&f[p[head]]+map[p[head]][j]<f[j]){
					bo[j]=1;
					f[j]=f[p[head]]+map[p[head]][j];
					tail++;
					p[tail]=j;
				}
			}
			bo[p[head]]=0;
		}
		for(int j=1;j<=n;++j){
			ansf[j]=max(ansf[j],f[j]);
		}
		map[x[i]][y[i]]=len[i];
		map[y[i]][x[i]]=len[i];
	}
	for(int i=1;i<=n;++i){
		if(ansf[i]==1e17){
			printf("-1 ");
		}
		else{
			printf("%lld ",ansf[i]);
		}
	}
	return 0;
}
