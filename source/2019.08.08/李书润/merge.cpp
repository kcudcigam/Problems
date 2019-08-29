#include<bits/stdc++.h>
using namespace std;
int fa[500001],size[500001],tag[500001];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
int find(int x)
{
	return fa[x]==x?fa[x]:find(fa[x]);
}
inline void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	if(size[x]>size[y])swap(x,y);
	tag[x]-=tag[y];
	fa[x]=y;
	size[y]+=size[x];
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,m;
	read(n),read(m);
	for(register int i=1;i<=n;++i)fa[i]=i,size[i]=1;
	register int op,x,y;
	for(register int i=1;i<=m;++i)
	{
		read(op),read(x),read(y);
		if(op==1)merge(x,y);
		else tag[find(x)]+=y;
	}
	for(register int i=1;i<=n;++i)
	{
		int t=i,ans=0;
		while(fa[t]!=t)ans+=tag[t],t=fa[t];
		ans+=tag[t];
		printf("%d ",ans);
	}
	return 0;
}
