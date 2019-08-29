#include<bits/stdc++.h>
using namespace std;
const int Maxn=300000+50;
const int INF=0x3f3f3f3f;

int Head[Maxn],NNext[Maxn],V[Maxn],W[Maxn],vis[Maxn];
int n,m,q,tot,ll=0,rr=-INF,lft,rit,mid,ans,flag;

void Add(int u,int v,int w){
	V[++tot]=v;W[tot]=w;NNext[tot]=Head[u];Head[u]=tot;
}


void dfs(int x,int y,int d){
	if(x==y){
		flag=1;return;
	}
	vis[x]=1;	
	for(int i=Head[x];i;i=NNext[i]){
		if(W[i]<=d&&vis[V[i]]==0){
			dfs(V[i],y,d);
		}	
	}
	vis[x]=0;
	return;
}
bool check(int x,int y,int d){
	flag=0;
	dfs(x,y,d);
	if(flag==1)return 1;
	else return 0;
}
void query(int x,int y){
	lft=ll;ans=rit=(rr+1);
	while(lft<rit){
		mid=((lft+rit)>>1);
		if(check(x,y,mid))ans=rit=mid;
		else lft=mid+1;
	}
	if(ans==(rr+1))printf("-1\n");
	else printf("%d\n",ans);
}

int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int i,j,x,y,z;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);Add(y,x,z);
		rr=max(rr,z);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		query(x,y);
	}
	return 0;
}


