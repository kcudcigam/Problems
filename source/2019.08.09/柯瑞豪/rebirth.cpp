#include<bits/stdc++.h>
using namespace std;
const int N=200010,M=500010,inf=1000000001;
int head[N],Next[M],ver[M],edge[M];
int n,m,tot;
int d1[N],d2[N],Bian[N];
priority_queue< pair<int,int> > q;
bool f[N];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')c=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;
}
void work(){
	d1[1]=d2[1]=0;
	q.push(make_pair(1,0));
	while(!q.empty()){
		int x=q.top().first;q.pop();
		f[x]=1;
		for(int i=head[x],y;i;i=Next[i]){
			y=ver[i];
			if(d1[x]+edge[i]<d1[y]){
				Bian[y]=i^1;
				d2[y]=d1[y];
				d1[y]=d1[x]+edge[i];
				if(!f[y])q.push(make_pair(y,-d1[y]));
			}
			else if(i!=Bian[x])d2[y]=min(d2[y],d1[x]+edge[i]);
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num=read();
	n=read();m=read();tot=1;
	for(int i=1;i<=n;i++)d1[i]=d2[i]=inf;
	for(int i=1,x,y,z;i<=m;i++){
		x=read();y=read();z=read();
		if(x==y)continue;
		add(x,y,z);
		add(y,x,z);
	}
	work();
	cout<<0<<" ";
	for(int i=2;i<=n;i++)
	if(d2[i]==inf)printf("-1 ");
	else printf("%d ",d2[i]);
	cout<<endl;
	return 0;
}

