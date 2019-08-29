#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	 char ch=getchar();
	 int f=0;
	 while(!isdigit(ch)) ch=getchar();
	 while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	 return f;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int Q;
	Q=read();
	while(Q--)
		{
			int n;
			n=read();
			int la=0;
			int lx=0,ly=0;
			bool flag=1;
			for(int i=1;i<=n;i++)
				{
					int t,x,y;
					t=read();
					x=read();
					y=read();
					int bs=abs(x-lx)+abs(y-ly);
					if(bs>t-la||((bs&1) != ((t-la)&1))) flag=0;
					la=t;
					lx=x;
					ly=y;
				}
			if(flag) puts("Yes");
			else puts("No");
		}
	return 0;
}


