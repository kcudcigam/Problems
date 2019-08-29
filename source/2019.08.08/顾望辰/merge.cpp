#include<cstdio>
#include<cctype>
int n,q,opt,x,y,fa[500010],ans[500010];
void qread(int& x)
{
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return ;
}
int getfa(int x)
{
	if(x==fa[x]) return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	int fx=getfa(x),fy=getfa(y);
	if(fx!=fy) fa[fx]=fa[fy];
	return ;
}
void add(int x,int y)
{
	int f=getfa(x);
	for(int i=1;i<=n;i++)
		if(f==getfa(i)) ans[i]+=y;
	return ;
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	qread(n),qread(q);
	for(int i=1;i<=n;i++) fa[i]=i;
	while(q--)
	{
		qread(opt),qread(x),qread(y);
		if(opt==1) merge(x,y);
		else add(x,y);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
