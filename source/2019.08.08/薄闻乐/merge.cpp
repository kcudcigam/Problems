#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m,l,x,y,fa[500001],ans[500001];
vector <int> v[500001];
void workk(int uu,int dep)
{
	fa[uu]=dep;
	for (int i=0;i<v[uu].size();i++)
	workk(v[uu][i],dep);
	return;
}
void work1(int fat,int s)
{
	int u=0,uuu=0;
	if(fa[fat]==fa[s])
	return ;
	if(fa[s]==s)
	{
		fa[s]=fa[fat];
		v[fat].push_back(s);
		return ;
	}
	if(fa[fat]==fat)
	{
		fa[fat]=fa[s];
		v[s].push_back(fat);
		return ;
	}
	u=fa[s];
	uuu=fa[fat];
	fa[u]=uuu;
	for (int i=0;i<v[u].size();i++)
	{
		int f=v[u][i];
		workk(f,uuu);
	}
	return;
}
void check(int wh,int tot)
{
	int s=fa[wh];
	for (int i=1;i<=n;i++)
	if(fa[i]==s)
	ans[i]+=tot;
	return ;
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for (int i=1;i<=m;i++)
	{
		read(l);
		read(x);
		read(y);
		if(l==1)
		{
			work1(x,y);
		}
		else {
			check(x,y);
		}
	}
	cout<<ans[1];
	for (int i=2;i<=n;i++)
	cout<<' '<<ans[i];
	return 0;
}
