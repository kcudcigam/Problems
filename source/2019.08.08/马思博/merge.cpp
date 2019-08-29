#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for (; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int fa[500005],ans[500005];

int check(int x)
{
	if(fa[x]=x) return x;
	else return fa[x]=check(fa[x]);
}

void merge(int a,int b)
{
	int x=check(a),y=check(b);
	if(x!=y) fa[x]=y;
	return ;
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,m,a,b;
	read(n);read(q);
	for(int i=1;i<=n;++i) fa[i]=i;
	int s=q;
	while(s--)
	{
		read(m);read(a);read(b);
		if(m==1) merge(a,b);
		if(m==2)
		{
			int fat=check(a);
			for(int i=1;i<=n;++i) 
			    if(fa[i]==fat) ans[i]+=b;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}

