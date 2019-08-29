#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
	R int f=1,num=0;
	R char ch=getchar();
	while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(0!=isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num*f;
}
int a[10][10];
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	a[1][1]=-1;a[1][2]=1;a[1][3]=-1;a[1][4]=1;a[1][5]=-1;
	
	a[2][1]=1;a[2][2]=-1;a[2][3]=-1;a[2][4]=1;a[2][5]= 1;
	
	a[3][1]=-1;a[3][2]=-1;a[3][3]=1;a[3][4]=1;a[3][5]=-1;
	
	a[4][1]=1;a[4][2]=1;  a[4][3]=1;a[4][4]=1;a[4][5]=-1;
	
	R int x=read(),y=read();
	if(x<=4&&y<=5&&(x!=0&&y!=0))
	{
		if(x==1&&y==1)printf("%d\n",1);
		else if(a[x][y]==-1)printf("%d\n",5);
		else printf("infinity\n");
	}
	else printf("infinity\n");
	return 0;
}
