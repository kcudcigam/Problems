#include<bits/stdc++.h>
using namespace std;
inline int dis(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ot=0,ox=0,oy=0,nt,nx,ny;
		bool flag=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&nt,&nx,&ny);
			int t=nt-ot;
			int d=dis(ox,oy,nx,ny);
			if(t<d || (t-d)&1==1)
			{
				flag=false;
			}
			swap(ot,nt);swap(ox,nx);swap(oy,ny);
		}
		if(flag==true)  printf("Yes\n");
		if(flag==false)  printf("No\n");
	}
	return 0;
}
