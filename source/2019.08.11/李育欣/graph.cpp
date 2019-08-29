#include<bits/stdc++.h>
using namespace std;
const int N=300001;
int n,m,Q,tot,maxx,f[N],u[N];
int ver[N],head[N],w[N],Next[N];
void add(int x,int y,int z){
	Next[++tot]=head[x];head[x]=tot;ver[tot]=y;w[tot]=z;
}
int find(int k){
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
}
bool bfs(int x,int y,int a){
	queue<int> q;
	q.push(x);u[x]=1;
	while(q.size()){
		int xx=q.front();q.pop();
		for(int i=head[xx];i;i=Next[i]){
			int yy=ver[i];
			if(w[i]>a)continue;
			if(!u[yy]){
				u[yy]=1;
				q.push(yy);
				if(yy==y)return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z,x1,x2;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
		maxx=max(maxx,z);
		x1=find(x);x2=find(y);
		if(x1!=x2)f[x1]=x2;
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y)){
			printf("-1\n");continue;
		}
		int l=1,r=maxx;
		while(l<r){
			int mid=(l+r)/2;
			memset(u,0,sizeof(u));
			if(bfs(x,y,mid)){
				r=mid-1;
			}
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
