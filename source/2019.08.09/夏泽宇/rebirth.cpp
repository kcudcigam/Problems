#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int tot=0;
int head[N],ver[N],edge[N],Next[N];
ll dist[N],subdist[N];
bool v[N];
queue<int>q;
void add(int x,int y,int len){
	ver[++tot]=y;
	edge[tot]=len;
	Next[tot]=head[x];
	head[x]=tot;
}
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
void spfa(){
	memset(v,0,sizeof(v));
	memset(dist,0x3f,sizeof(dist));
	memset(subdist,0x3f,sizeof(subdist));
	q.push(1);
	dist[1]=0;
	v[1]=1;
	while(q.size()){
		int t=q.front();
//		cout<<t<<endl;
		q.pop();
		v[t]=0;
		for(int i=head[t];i;i=Next[i]){
			int p=ver[i],d=edge[i];
			if(dist[p]>dist[t]+d){
				subdist[p]=dist[p];
				dist[p]=dist[t]+d;
//				cout<<t<<" "<<p<<" "<<subdist[p]<<" "<<dist[p]<<endl;
				if(!v[p]){
					q.push(p);
					v[p]=1;
				}
			}
			else {
				if(dist[t]+d<subdist[p])subdist[p]=dist[t]+d;
//				cout<<t<<" "<<p<<" "<<subdist[p]<<" "<<dist[p]<<endl;
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num=read(),n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),len=read();
		if(x==y)continue;
		add(x,y,len);
		add(y,x,len);
	}
	spfa();
	ll cmp=0x3f3f3f3f3f3f3f3f;
	printf("%d ",0);
	for(int i=2;i<=n;i++){
		if(cmp==subdist[i])printf("%d ",-1);
		else printf("%lld ",subdist[i]);
	}
	puts("");
	return 0;
}
/*
1
4 8
1 2 4
1 3 5
1 3 1
2 3 6
2 3 2
2 4 5
3 4 8
2 3 2
*/

