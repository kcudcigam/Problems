#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int R,C,a[256][256],tag[256][256],res;
void dfs(int R,int C,int v,int tg)
{
	res++; tag[R][C]=tg;
	if(R&&a[R-1][C]==v&&!tag[R-1][C]) dfs(R-1,C,v,tg);
	if(C&&a[R][C-1]==v&&!tag[R][C-1]) dfs(R,C-1,v,tg);
	if(R+1<256&&a[R+1][C]==v&&!tag[R+1][C]) dfs(R+1,C,v,tg);
	if(C+1<256&&a[R][C+1]==v&&!tag[R][C+1]) dfs(R,C+1,v,tg);
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&R,&C);
	a[0][0]=a[1][0]=a[0][1]=1; a[1][1]=-1;
	for(int m=2;m<256;m*=2)
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
			{
				a[i+m][j]=a[i][j+m]=a[i][j];
				a[i+m][j+m]=-a[i][j];
			}
	dfs(0,0,1,1);
	if(tag[R][C]==1) { puts("infinity"); return 0; }
	res=0;
	dfs(R,C,a[R][C],2);
	printf("%d\n",res);
	return 0;
}
