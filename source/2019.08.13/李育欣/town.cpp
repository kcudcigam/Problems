#include<bits/stdc++.h>
using namespace std;
const int N=3000001;
int n,tot,d[N],v[N];
int head[N],nxt[N],ver[N];
inline void add(int x,int y){
	nxt[++tot]=head[x];head[x]=tot;ver[tot]=y;
	nxt[++tot]=head[y];head[y]=tot;ver[tot]=x;
}
inline int dp(int x){
	int ans=0;v[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(v[y])continue;
		dp(y);
		ans=max(ans,d[x]+d[y]+1);
		d[x]=max(d[x],d[y]+1);
	}
	return ans;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		if(i==1)printf("1\n");
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		printf("%d\n",dp(x));
	}
	return 0;
}


