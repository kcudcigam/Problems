#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=500050;
int ri() {    // ¿ì¶Á 
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m,a[maxn],b[maxn];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri(),m=ri();
	for(int i=1;i<=n;i++)
	a[i]=ri();
	for(int i=1;i<=n;i++)
	b[i]=ri();
	while(m--)
	{
		int opt=ri();
		if(opt==1) 
		{
			int x,y,z;
			x=ri(),y=ri(),z=ri();
			if(x==0) a[y]=z;
			else b[y]=z;
			continue;
		}
		
		int l1,r1,l2,r2;
		l1=ri(),r1=ri(),l2=ri(),r2=ri();
		
		int head1,head2,tail1,tail2;
		head1=l1,head2=l2,tail1=r1,tail2=r2;
		int cur=(r1-l1+r2-l2+2+1)/2,now;
		while(cur)
		{
			if(head1<=tail1&&head2<=tail2)
			{
				if(a[head1]<=b[head2]) now=a[head1],head1++;
				else now=b[head2],head2++;
				cur--;
				continue;
			}
			if(head1<=tail1)
			now=a[head1],head1++;
			if(head2<=tail2)
			now=b[head2],head2++;
			cur--;
		}
		printf("%d\n",now);
	}
	return 0;
}














