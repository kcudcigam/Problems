#include<bits/stdc++.h>
using namespace std;
int T,n,t,x,y,lt,lx,ly,tt,l1,l2;
bool f;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		lx=0;;ly=0;lt=0;
		f=true;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&t,&x,&y);
			tt=t-lt;
			if (abs(x-lx)+abs(y-ly)>tt)
			{
				f=false;
				break;
			}
			l1=tt%2;l2=(abs(x-lx)+abs(y-ly))%2;
			if (l1!=l2)
			{
				f=false;
				break;
			}
			lt=t;lx=x;ly=y;
		}
		if (f==true)
		cout << "Yes" << endl;
		else
		cout << "No" << endl;
	}
	return 0;
}

