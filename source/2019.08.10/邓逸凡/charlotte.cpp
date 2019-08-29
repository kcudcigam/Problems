#include<bits/stdc++.h>
using namespace std;
int read()
{
	int a=0; char c=getchar();
	for  (;!isdigit(c);c=getchar());
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
void work()
{
	int N=read();
	int X=0,Y=0,lst=0;
	bool flag=true;
	for  (int i=1;i<=N;i++)
		{
			int zz=read(),xx=read(),yy=read();
			if  (!flag)	continue;
			int nd=abs(xx-X)+abs(yy-Y);
			if  (nd>zz-lst||(zz-lst)%2!=nd%2)
				flag=false;
		}
	if  (flag)
		printf("Yes\n");
	else
		printf("No\n");
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T=read();
	for  (int i=1;i<=T;i++)
		work();
	return 0;
}


