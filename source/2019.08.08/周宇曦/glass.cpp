#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
    int RR=1;FF=0;char CH=getchar();
    while(!isdigit(CH)&&CH!='-') CH=getchar();
    if(CH=='-') RR=-1;else FF=CH^48;CH=getchar();
    while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar(); FF*=RR;
}
long long lowbit(long long ai)
{
	return ai & -ai;
}
int main()
{
    freopen("glass.in","r",stdin);
    freopen("glass.out","w",stdout);
	long long n,k,ki=1;
	read(n),read(k);
	long long yi=n;
	while(1)
	{
		long long ni=n,ansi=0;
		while(ni) ni-=lowbit(ni),ansi++;
		if(ansi<=k)
		{
			cout<<n-yi<<endl;
			return 0;
		}
		n+=lowbit(n);
	}
    return 0;
}



