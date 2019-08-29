#include<bits/stdc++.h>
#define maxn 100010
#define inf 0x3f3f3f3f
using namespace std;
struct node{
	int t,x,y;
};
node a[maxn];
int T,n;
bool p;
void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
bool cmp(node a,node b)
{
	return a.t<b.t;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	fread(T);
	while(T--)
	{
		fread(n);
		for(int i=1;i<=n;i++)
		fread(a[i].t),fread(a[i].x),fread(a[i].y);
		sort(a+1,a+n+1,cmp);
		p=false;
		for(int i=1;i<=n;i++)
		{
			if(abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)>a[i].t-a[i-1].t||(a[i].t-a[i-1].t-abs(a[i].x-a[i-1].x)-abs(a[i].y-a[i-1].y))%2!=0) break;
			if(i==n) p=true;
		}
		if(p) puts("Yes");
		else puts("No");
	}
	return 0;
}


