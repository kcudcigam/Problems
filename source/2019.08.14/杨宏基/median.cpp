#include<cstdio>
#include<iostream>
using namespace std;
int a[4][1000010],box[1000010];
int n,m;
int ri()
{
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=ri();
	while(m--)
	{
		int o,x,y,z,u,v;
		o=ri();
		if(o==1)
		{
			x=ri();
			y=ri();
			z=ri();
			a[x][y]=z;
		}
		else
		{
			x=ri();
			y=ri();
			u=ri();
			v=ri();
			int ta=x,tb=u,i;
			for(i=1;i<=y-x+v-u+2&&ta<=y&&tb<=v;i++)
			{
				if(a[0][ta]<a[1][tb])
					box[i]=a[0][ta],ta++;
				else
					box[i]=a[1][tb],tb++;
			}
			while(ta<=y)
				box[i++]=a[0][ta],ta++;
			while(tb<=v)
				box[i++]=a[1][tb],tb++;
			printf("%d\n",box[(y-x+v-u+2)/2+1]);
		}
	}
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
