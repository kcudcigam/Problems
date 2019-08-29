#pragma GCC optimize 2
#include<bits/stdc++.h>
using namespace std;
const int maxn=5E5+5;
const int inf=1E9;
int n,m,a[maxn],b[maxn];
inline int read()
{
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	int sum=ch-'0';
	ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar('0'+x%10);
}
inline void writen(int x)
{
	write(x);
	putchar('\n');
}
int TOT=0;
inline int ask(int L1,int R1,int L2,int R2)
{
	++TOT;
	int len=(R1-L1+1+R2-L2+1)/2+1;
	int len1=R1-L1+1,len2=R2-L2+1;
	int L=0,R=inf,mid,last1=-1,last2=-1;
	int flag=0,pos1,pos2;
	while(L<R)
	{
		mid=(L+R)>>1;
		if(flag==0)
		{
			pos1=upper_bound(a+L1,a+R1+1,mid)-a;
			pos2=upper_bound(b+L2,b+R2+1,mid)-b;
		}
		else
		{
			if(flag==1)
			{
				pos1=upper_bound(a+L1,a+last1+1,mid)-a;
				pos2=upper_bound(b+L2,b+last2+1,mid)-b;
			}
			else
			{
				pos1=upper_bound(a+last1,a+R1+1,mid)-a;
				pos2=upper_bound(b+last2,b+R2+1,mid)-b;
			}
		}
		--pos1,--pos2;
		if(pos1-L1+1+pos2-L2+1>=len)
			R=mid,flag=1;
		else
			L=mid+1,flag=-1;
		last1=pos1,last2=pos2;
	}
	return L;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),y=read(),z=read();
			if(x==0)
				a[y]=z;
			else
				b[y]=z;
		}
		else
		{
			int L1=read(),R1=read(),L2=read(),R2=read();
			writen(ask(L1,R1,L2,R2));
		}
	}
	return 0;
}

