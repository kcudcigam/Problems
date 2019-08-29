#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int to,nt,w;
}p[100005];
int INF=100000000;
int f[100005],dis[100005];
int head[100005],tot,ans;
void add(int u,int v,int w)
{
	tot++;
	p[tot].to=v;
	p[tot].w=w;
	p[tot].nt=head[u];
	head[u]=tot;
}
int find(int x)
{
	if(f[x]==x){
		return x;
	}
	else{
		return f[x]=find(f[x]);
	}
}
void hb(int p,int q)
{
	p=find(p);q=find(q);
	if(p!=q){
		f[p]=q;
	}
}
queue<int>que;
void spfa(int l)
{
	int x,i;
	que.push(l);
	while(!que.empty()){
		x=que.front();
		que.pop();
		for(i=head[x];i;i=p[i].nt){
			int t=p[i].to;
			if(dis[t]>dis[x]+p[i].w){
				dis[t]=dis[x]+p[i].w;
				ans=max(ans,dis[t]);
				que.push(t);
			}
		}
	}
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n,i,j,k,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		f[i]=i;
	}
	for(i=1;i<n;i++){
		ans=-INF;
		scanf("%d%d",&a,&b);
		add(a,b,1);
		add(b,a,1);
		hb(a,b);
		
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				dis[k]=INF;
			}
			if(find(j)==find(a)||find(j)==find(b)){
				dis[j]=0;
				spfa(j);
//				for(k=1;k<=n;k++){
//					if(dis[k]!=INF){
//						ans=max(ans,dis[k]);
//					}
//				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


