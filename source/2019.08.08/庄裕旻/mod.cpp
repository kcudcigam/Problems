#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &x)
{
	x=0; int t=0,f=1;
	while(t=getchar(),(t<'0'||t>'9')&&t!='-') t=getchar();
	if(t!='-') x=t-'0';
	else f=-1;
	while(t=getchar(),t>='0'&&t<='9') x=x*10+t-'0';
	x=x*f;
}
int T,n; LL p,f;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(T);
	while(T-->0)
	{
		read(n); read(p);
		if(n==1) cout<<0<<endl;
		else if(n==2) cout<<2%p<<endl;
		else
		{
			f=2;
			for(int i=3;i<=n;i++)
				if(i&1) f=i*(f+i-1)%p;
				else f=(i*f+(i-1)*(i-1)+1)%p;
			cout<<f%p<<endl;
		}
	}
	return 0;
}
/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938

*/
