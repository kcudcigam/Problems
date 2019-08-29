#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int g[100];
}p[300001];
int Map[3005][3005],s[500005],p1[500005];
int u,v,t,x,y,i,tot[500005],tot1[500005];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	if(n<=3000){
		for(i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			Map[u][v]=Map[v][u]=1;
		}
		while(q--){
			scanf("%d",&t);
			if(t==0){
				scanf("%d",&x);
				printf("%d\n",s[x]);
			}
			else{
				scanf("%d%d",&x,&y);
				s[x]+=y;
				for(i=1;i<=n;i++){
					if(i==x) continue;
					if(Map[x][i]){
						s[i]+=y;
					}
				}
			}
		}
		return 0;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(u==1){
			tot1[u]++;
			p1[tot1[u]]=v;
		}
		if(v==1){
			tot1[v]++;
			p1[tot1[v]]=u;
		}
		tot[u]++;tot[v]++;
		p[u].g[tot[u]]=v;
		p[v].g[tot[v]]=u;
	}
	while(q--){
		scanf("%d",&t);
		if(t==0){
			scanf("%d",&x);
			printf("%d\n",s[x]);
		}
		else{
			scanf("%d%d",&x,&y);
			s[x]+=y;
			if(x!=1){
				for(i=1;i<=tot[x];i++){
					s[p[x].g[i]]+=y;
				}
			}
			else{
				for(i=1;i<=tot1[x];i++){
					s[p1[i]]+=y;
				}
			}
		}
	}
	return 0;
}
