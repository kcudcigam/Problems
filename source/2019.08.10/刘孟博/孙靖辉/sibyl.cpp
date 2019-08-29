#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define re register int 
const int maxn=300005;
int head[maxn],ver[2*maxn],nxt[2*maxn];
struct node{
	ll add;
}a[maxn];
int tot,n,m,q;
inline void add1(int x,int y)
{
	ver[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

inline void change(int x,int z)
{
	for(re i=head[x];i;i=nxt[i]) {
		int y=ver[i]; a[y].add+=z;
	}
}

inline ll ask(int x)
{
	ll ans=0;
	for(re i=head[x];i;i=nxt[i]) {
		int y=ver[i]; if(a[y].add) {
			ans+=a[y].add;
		}
	}
	return ans;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(re i=1;i<=m;i++) {
		int x,y; scanf("%d%d",&x,&y);
		add1(x,y); add1(y,x);
	}
	for(re i=1;i<=q;i++) {
		int type,x; scanf("%d%d",&type,&x); 
		if(!type) {
			ll ans=ask(x);
			printf("%lld\n",ans);
		}
		
		else {
			int z;scanf("%d",&z);
			change(x,z);
		}
	}
	return 0;
}
