#include<bits/stdc++.h>

#define FILE "refrain"

using namespace std;

template<typename T>
void read(T &x)
{
	bool f=0;char c=getchar();x=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=1;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	if(f) x=-x;
}

int Num,n,m1,m2;
bitset<200005> a,b;

int main()
{
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	read(Num),read(n),read(m1),read(m2);
	for(int i=0;i<m1;++i)
	{
		int x,y;
		read(x),read(y);
		a[x]=a[y]=1;
	}
	for(int i=0;i<m2;++i)
	{
		int x,y;
		read(x),read(y);
		b[x]=b[y]=1;
	}
	if(n==1||n==2)
		cout<<0;
	else
	{
		
	}
	return 0;
}

