#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
int n,m,v[1000010]; ll d[200010];
int head[200010],ver[1000010],Next[1000010],tot=1;ll edge[1000010];

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
} 

inline ll read_long(){
	ll f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

void add(int x,int y,ll z){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;edge[tot]=z;
}

void dijkstra(){
	priority_queue< pair<ll,int> > q;
	for(int i=1;i<=n;i++)d[i]=(1<<30);
	d[1]=0;q.push(make_pair(0,1));
	while(q.size()){
		int x=q.top().second; q.pop();
		if(v[x])continue;v[x]=1;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];ll z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
    int T;scanf("%d",&T);
    n=read();m=read();
    for(int i=1;i<=m;i++){
    	int a=read(),b=read();ll c=read_long();
    	if(a!=b)add(a,b,c),add(b,a,c);
	}
	dijkstra();    
   
	printf("0 ");
	for(int x=2;x<=n;x++){
		ll ans=(1<<30); 
		for(int i=head[x];i;i=Next[i])
		  if(d[ver[i]]+edge[i]>d[x]&&d[ver[i]]-edge[i]!=d[x])
		    ans=min(ans,d[ver[i]]+edge[i]);
		if(ans>=(1<<30))printf("-1 ");
		else printf("%lld ",ans); 
	}
	return 0;
}

