#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,q;
int nms[500001],zz[500001];
void init()
{
	for(int i=1;i<=n;++i)
	{
		nms[i]=i;
	}
}
int find(int x)
{
	if(nms[x]==x)
	{
		return x;
	}
	return nms[x]=find(nms[x]);
}
void merge(int a,int b)
{
	nms[find(b)]=find(a);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>q;
	init();
	for(int i=0;i<q;i++)
	{
		int op,x,y;
		read(op);
		read(x);
		read(y);
		if(op==2)
		{
			int p=find(x);
			for(int i=1;i<=n;i++)
			{
				if(find(i)==p)
				{
					zz[i]+=y;
				}
			}
		}
		else
		{
			merge(x,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",zz[i]);
	}
}


