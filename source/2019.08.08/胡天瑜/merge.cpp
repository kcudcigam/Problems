#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=500010;

int n,q;
int fa[MAXN];
int tag[MAXN];
int aa[MAXN];

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
	fa[get(x)]=get(y);
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=q;++i)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		if(type==2)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int root=get(a);
			for(int i=1;i<=n;++i)
			{
				if(get(i)==root)
				{
					aa[i]+=b;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",aa[i]);
	}
	return 0;
}

