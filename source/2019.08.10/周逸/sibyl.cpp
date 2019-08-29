#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,m,Q,tot,ans;
int Head[maxn],Next[maxn<<1],V[maxn<<1];
int vis[maxn],W1[maxn],W2[maxn],in[maxn];
void add(int u,int v){
	V[++tot]=v;
	Next[tot]=Head[u];
	Head[u]=tot;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	int i,j;
	int op,u,v,w;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(u==v)
			continue;
		add(u,v);
		add(v,u);
		in[u]++;
		in[v]++;
	}
	for(i=2;i<=n;i++)
		if(in[i]>=10)
			break;
	if(i==n+1){
		for(i=Head[1];i;i=Next[i])
			in[V[i]]=-1;
		for(i=1;i<=Q;i++){
			scanf("%d",&op);
			if(op){
				scanf("%d%d",&u,&w);
				if(u!=1)
					for(j=Head[u];j;j=Next[j]){
						v=V[j];
						if(vis[v]==i)
							continue;
						W2[v]+=w;
						vis[v]=i;
					}
				W1[u]+=w;
			}
			else{
				scanf("%d",&u);
				if(in[u]!=-1)
					printf("%d\n",W1[u]+W2[u]);
				else
					printf("%d\n",W1[u]+W2[u]+W1[1]);
			}
		}
		return 0;
	}
	for(i=1;i<=n;i++)
		if(in[i]>10)
			in[i]=-1;
	for(i=1;i<=Q;i++){
		scanf("%d",&op);
		if(op){
			scanf("%d%d",&u,&w);
			if(in[u]!=-1)
				for(j=Head[u];j;j=Next[j]){
					v=V[j];
					if(vis[v]==i)
						continue;
					W2[v]+=w;
					vis[v]=i;
				}
			W1[u]+=w;
		}
		else{
			scanf("%d",&u);
			if(in[u]==-1)
				printf("%d\n",W1[u]+W2[u]);
			else{
				for(j=Head[u];j;j=Next[j]){
					v=V[j];
					if(in[v]==-1)
						break;
				}
				if(j)
					printf("%d\n",W1[u]+W1[v]);
				else
					printf("%d\n",W1[u]+W2[u]);
			}
		}
	}
	return 0;
}


