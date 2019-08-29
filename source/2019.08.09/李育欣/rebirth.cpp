#include<bits/stdc++.h>
using namespace std;
const int N=100001,M=500001;
int tot,num,n,m;
int ver[M],next[M],w[M],head[N];
int d[M],v[M],qian[N],d1[M],v1[M];
priority_queue< pair<int,int> > q;
void add(int x,int y,int z){
	next[++tot]=head[x];head[x]=tot;ver[tot]=y;w[tot]=z;
}
void Dj1(int g){
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(v,0,sizeof(v));
	while(q.size())q.pop();
	d[g]=0;
	q.push(make_pair(0,g));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=next[i]){
			int y=ver[i];
			if(d[y]>d[x]+w[i]){
				d[y]=d[x]+w[i];
				q.push(make_pair(-d[y],y));
				qian[y]=x;
			}
		}
	}
}
void Dj2(int g,int s){
	memset(d1,0x3f3f3f3f,sizeof(d1));
	memset(v1,0,sizeof(v1));
	while(q.size())q.pop();
	d1[g]=0;v1[s]=1;
	q.push(make_pair(0,g));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(v1[x])continue;
		v1[x]=1;
		for(int i=head[x];i;i=next[i]){
			int y=ver[i];
			if(d1[y]>d1[x]+w[i]){
				d1[y]=d1[x]+w[i];
				q.push(make_pair(-d1[y],y));
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==y)continue;
		add(x,y,z);add(y,x,z);
	}
	if(num<=3)
	Dj1(1);
	for(int i=1;i<=n;i++){
		if(i==1){printf("%d ",0);continue;}
		int ans=0;
		for(int j=head[i];j;j=next[j]){
			Dj2(i,j);
			if(d1[1]!=0x3f3f3f3f)ans=max(ans,d1[1]);	
		}
		if(ans!=0)printf("%d ",ans);
		else printf("%d ",-1);
	}
	return 0;
}

