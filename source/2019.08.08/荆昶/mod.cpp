#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int s,b[10000001],n,p;
int a[10000001],lasta[10000001];
void f(int l)
{
	if(l>n)
	{
		for(int i=1;i<=n;i++)
		if(a[i]!=lasta[i]) 
		{
			s++;
			lasta[i]=a[i];
		}
		s%=p;
		return;
	} 
	for(int i=1;i<=n;i++)
	if(!b[i])
	{
		a[i]=l;
		b[i]=1;
		f(l+1);
		b[i]=0;
	}
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	read(q);
	while(q--)
	{
		read(n);read(p);
		for(int i=1;i<=n;i++) lasta[i]=i;
		s=0;
		f(1);
		printf("%d\n",s);
	}
	return 0;
}

