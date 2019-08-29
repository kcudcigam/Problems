#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int rd()
{
	int x=0; char ch=0; bool s=0;
	while(!isdigit(ch)){s|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return s?-x:x;
}
struct txy{
	int t,x,y;
};
bool cMp(txy a,txy b)
{
	return a.t<b.t;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T=rd();
	while(T--)
	{
		int n=rd();
		txy a[n+3];
		a[0].t=0; a[0].x=0; a[0].y=0;
		for(int i=1; i<=n; ++i)
		{
			a[i].t=rd(); a[i].x=rd(); a[i].y=rd();
		}
		sort(a+1,a+n+1,cMp);
		bool ans=0;
		for(int i=1; i<=n; ++i)
		{
			if(abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)>abs(a[i].t-a[i-1].t)
			|| (abs(a[i].t-a[i-1].t)-abs(a[i].x-a[i-1].x)-abs(a[i].y-a[i-1].y))%2==1)
			{
				ans=1;
				break;
			}
		}
		puts(ans==1?"No":"Yes");
	}
	return 0;
}

