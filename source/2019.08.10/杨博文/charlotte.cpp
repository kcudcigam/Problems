#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;char c;bool f=0;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);return *this;
	}
}yin;
int n;
const int maxn=1e5+100;
int t[maxn],x[maxn],y[maxn];
int main()
{
	fre("charlotte");
	int ttt;
	yin>>ttt;
	while(ttt--)
	{
		yin>>n;
		for(int i=1;i<=n;i++)yin>>t[i]>>x[i]>>y[i];
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			if(t[i]-t[i-1]<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])||(t[i]-t[i-1]-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))&1){f=0;break;}
		}
		if(f)puts("Yes");else puts("No");
	}
	return 0;
}
