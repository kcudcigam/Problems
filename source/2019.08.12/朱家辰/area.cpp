#include<bits/stdc++.h>
#define maxn 40000
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int p[33],m,n,ans;
int calc(int x,int y)
{
	if(x==1&&y==1) return 1;
	if(x==1&&y==2) return 1;
	if(x==2&&y==1) return 1;
	if(x==2&&y==2) return -1;
	int k,t=max(x,y);
	for(k=1;k<=30;k++)
		if(p[k]<t&&t<=p[k+1])
			break;
	if(x>p[k]&&y>p[k])
	return -calc(x-p[k],y-p[k]);
	if(x>p[k]) x-=p[k];
	if(y>p[k]) y-=p[k];
	return calc(x,y);
}
void dfs(int x,int y,int k,int lasx,int lasy)
{
	ans++;
	if(ans>=maxn) return;
	if(calc(x+1,y)==k&&lasx!=-1) dfs(x+1,y,k,1,0);
	if(ans>=maxn) return;
	if(x-1>0&&calc(x-1,y)==k&&lasx!=1) dfs(x-1,y,k,-1,0);
	if(ans>=maxn) return;
	if(calc(x,y+1)==k&&lasy!=-1) dfs(x,y+1,k,0,1);
	if(ans>=maxn) return;
	if(y-1>0&&calc(x,y-1)==k&&lasy!=1) dfs(x,y-1,k,0,-1);
	if(ans>=maxn) return;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=31;i++)
	p[i]=p[i-1]*2;
	cin>>n>>m;
	n++,m++;
	dfs(n,m,calc(n,m),0,0);
	if(ans>=maxn) puts("infinity");
	else printf("%d",ans);
	return 0;
}


