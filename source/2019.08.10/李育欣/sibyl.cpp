#include<bits/stdc++.h>
using namespace std;
const int M=300001;
int n,m,Q,tot,top,u[M],ad[M];
int head[M],ver[M],next[M],Stack[M];
long long d[M];
void add(int x,int y){
	next[++tot]=head[x];head[x]=tot;ver[tot]=y;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int o,x,y;
	scanf("%lld%lld%lld",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		add(x,y);add(y,x);
	}
	while(Q--){
		scanf("%d",&o);
		if(o==0){
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				if(ad[i]){
					d[i]+=ad[i];
					memset(u,0,sizeof(u));
					for(int j=head[i];j;j=next[j]){
						if(!u[ver[j]]){
							d[ver[j]]+=ad[i];u[ver[j]]=1;
						}
					}
				}
			}
			memset(ad,0,sizeof(ad));
			printf("%lld\n",d[x]);
		}
		if(o==1){
			scanf("%d%d",&x,&y);
			ad[x]+=y;
		}
	}
	return 0;
}
