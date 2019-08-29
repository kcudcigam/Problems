#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
int N[maxn],V[maxn],W[maxn],H[maxn],tot=0;
bool vis[maxn];
void add(int u,int v){
	V[++tot]=v;N[tot]=H[u];H[u]=tot;
}
queue<int> q;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,Q,i,u,v,op,y,j;
	long long ans,ans1=0;
	scanf("%d%d%d",&n,&m,&Q);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		if(u==1) vis[v]=1;
		if(v==1) vis[u]=1;
	}
	for(i=1;i<=Q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&u,&y);W[u]+=y;
			if(vis[u]) q.push(u);
			if(u==1) ans1+=y;
		}
		else{
			ans=0;
			scanf("%d",&u);
			if(u==1){
				while(!q.empty()){
					v=q.front();q.pop();
					ans1+=(long long)W[v];
				}
				printf("%lld\n",ans1);
			}
			else{
				 for(j=H[u];j;j=N[j]){
				v=V[j];
				ans+=(long long)W[v];
			}
			ans+=(long long)W[u];
			printf("%lld\n",ans);
			}
		}
	}
	return 0;
}

