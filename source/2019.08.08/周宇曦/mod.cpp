#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
long long ai[10000100];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n; long long p;
		read(n),read(p);
		ai[0]=ai[1]=0,ai[2]=2;
		for(int i=3;i<=n;i++)
			ai[i]=(ai[i-1]*(i%p)%p+((i%2)?(i-1)%p*(i%p)%p:((i-1)%p*((i-1)%p)%p+1)%p))%p;
		printf("%lld\n",ai[n]);
	}
	return 0;
}

