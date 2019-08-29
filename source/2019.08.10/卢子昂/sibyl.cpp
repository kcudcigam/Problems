#include<bits/stdc++.h>
using namespace std;
const int Maxn=300000+10;
const int Maxm=600000+10;
int Head[Maxn],Next[Maxm],V[Maxm];
int a[Maxn],vis[Maxn];
int tot,n,m,q;
void Add(int u,int v){
	V[++tot]=v;Next[tot]=Head[u];Head[u]=tot;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int i,j,x,y,type,v,cnt=0,ans=0;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Add(x,y);Add(y,x);
	}
	for(i=1;i<=q;i++){
		scanf("%d",&type);
		if(!type){
			ans=0;
			scanf("%d",&x);
			cnt++;
			ans+=a[x];
			for(i=Head[x];i;i=Next[i]){
				if(vis[V[i]]!=cnt){
					ans+=a[V[i]];					
					vis[V[i]]=cnt;
				}
			}
			printf("%d\n",ans);	
		}
		else{
			scanf("%d%d",&x,&y);
			a[x]+=y;
		}
	}
	return 0;
}


