#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x){
	char ch=getchar();
	x=0;T f=0;
	while (!isdigit(ch)){f|=ch=='-';ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

bool v[300010];
int ans,tot,n;
int ver[300010],next[300010],head[300010];
int d[300010],fa[300010];

void add(int x,int y){
	ver[++tot]=y;next[tot]=head[x];head[x]=tot;
}

void dp(int x){
	v[x]=1;
	for (int i=head[x];i;i=next[i]){
		int y=ver[i];
		if (v[y])	continue;
		fa[y]=x;
		dp(y);
		ans=max(ans,d[x]+d[y]+1);
		d[x]=max(d[x],d[y]+1);
	}
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	
	read(n);
	for (int i=1;i<=n;++i)	fa[i]=i;
	int x,y;
	for (int i=1;i<n;++i){
		ans=0;
		read(x);read(y);add(x,y);add(y,x);
		if (fa[x]!=x&&fa[y]==y){
			fa[y]=x;
			for (int i=head[x];i;i=next[i]){
				ans=max(ans,d[x]+d[ver[i]]+1);
				d[x]=max(d[x],d[ver[i]]+1);
			}
		}	else 
		if (fa[y]!=y&&fa[x]==x){
			fa[x]=y;
			for (int i=head[y];i;i=next[i]){
				ans=max(ans,d[y]+d[ver[i]]+1);
				d[y]=max(d[y],d[ver[i]]+1);
			}
		}	else
		if (fa[x]==x&&fa[y]==fa[y]){
			fa[y]=x;
			for (int i=head[x];i;i=next[i]){
				ans=max(ans,d[x]+d[ver[i]]+1);
				d[x]=max(d[x],d[ver[i]]+1);
			}
		}	else{
			fa[y]=x;
			memset(d,0,sizeof(d));
			memset(v,0,sizeof(v));
			dp(x);
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}


