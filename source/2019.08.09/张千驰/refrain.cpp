#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const long long mod=1e9+7;

int num,n,m1,m2,a[200010];
bool yin[1001][1001],yang[1001][1001],x,y;
long long cnt=0;

int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	memset(yin,false,sizeof(yin));
	memset(yang,false,sizeof(yang));
	for (register int i=1;i<=m1;++i)
	{
		scanf("%d%d",&x,&y);
		yin[x][y]=yin[y][x]=true;
	}
	for (register int i=1;i<=m2;++i)
	{
		scanf("%d%d",&x,&y);
		yang[x][y]=yang[y][x]=true;
	}
	if (num==1)
	{
		printf("%d\n",0);
		return 0;
	}	

	for (register int i=1;i<=n;++i)
		a[i]=i;
	while (next_permutation(a+1,a+n+1))
	{
		for (register int i=1;i<=n-1;++i)
		{
			for (register int j=i+1;j<=n;++j)
				if ((yin[i][j] && !yin[a[i]][a[j]]) || (yang[i][j] && !yang[a[i]][a[j]]) || (!yin[i][j] && yin[a[i]][a[j]]) || (!yang[i][j] && yang[a[i]][a[j]]))
				{
					++cnt;
					break;
				}
			break;
		}
		
	}
	printf("%lld\n",cnt%mod);
	return 0;
}


