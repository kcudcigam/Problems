#include<bits/stdc++.h>
using namespace std;
struct wyh{
	int x,y;
}a[300005];
int b[300005];
int n,m,Q,type,c,X,Y;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&Q);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(i=1;i<=Q;i++)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&X,&Y);
			b[X]+=Y;
			for(j=1;j<=m;j++)
			{
				if(a[j].x==X)
				{
					b[a[j].y]+=Y;
				}
				if(a[j].y==X)
				{
					b[a[j].x]+=Y;
				}
			}
		}
		if(type==0)
		{
			scanf("%d",&X);
			printf("%d\n",b[X]);
		}
	}
	return 0;
}
