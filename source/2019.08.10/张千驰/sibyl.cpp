#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n,m,q,x,y,type;

struct point
{
	int val;
	vector <int> v;
}a[300010];

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	while (m--)
	{
		scanf("%d%d",&x,&y);
		a[x].v.push_back(y);
		a[y].v.push_back(x);
	}
	while (q--)
	{
		scanf("%d",&type);
		if (type)
		{
			scanf("%d%d",&x,&y);
			a[x].val+=y;
			for (vector <int>::iterator it=a[x].v.begin();it!=a[x].v.end();++it)
				a[*it].val+=y;
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",a[x].val);
		}
	}
	return 0;
}



