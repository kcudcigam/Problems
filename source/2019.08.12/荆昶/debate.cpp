#include<bits/stdc++.h>
#define MAXN 400005
using namespace std;
struct pp{
	int a;
	bool zc[2];
}r[MAXN];
bool bk[MAXN];
bool comp(pp a,pp b)
{
	return a.a>b.a;
}
int i=0;
int n,t=0;
int fd()
{
	while(++i<=n)
	{
		if(r[i].zc[1]&&!r[i].zc[0])
		return i;
	}
	return 0;
}
int ans;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char h;
		getchar();
		h=getchar();
		if(h=='1') r[i].zc[0]=1;
		h=getchar();
		if(h=='1') r[i].zc[1]=1;
		scanf("%d",&r[i].a);
	}
	sort(r+1,r+n+1,comp);
	int fl=1;
	for(int i=1;i<=n;i++)
	{
		if(r[i].zc[0]&&r[i].zc[1])
		{
			t++;
			bk[i]=1;
			ans+=r[i].a;
		}
		else if(fl&&r[i].zc[0])
		{
			int ls=fd();
			if(ls==-1)
			fl=0;
			else
			{
				bk[ls]=bk[i]=1;
				ans+=r[i].a+r[ls].a;
			}
		}
	}
	for(int i=1;i<=n&&t;i++)
	if(!bk[i])
	{
		t--;
		ans+=r[i].a;
	}
	printf("%d",ans);
	return 0;
}

