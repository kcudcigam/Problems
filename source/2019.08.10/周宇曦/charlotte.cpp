#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar(); F*=R;
}
struct place{
	int ti,xi,yi;
	friend bool operator < (place a,place b){return a.ti<b.ti;}
}pi[100010];
int jl(int i){return abs(pi[i].xi-pi[i-1].xi)+abs(pi[i].yi-pi[i-1].yi);}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n;
		read(n);
		for(int i=1;i<=n;i++)
			read(pi[i].ti),read(pi[i].xi),read(pi[i].yi);
		sort(pi+1,pi+n+1);
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			if(pi[i].ti-pi[i-1].ti<jl(i)) {fl=1,puts("No");break;}
			else if((pi[i].ti-pi[i-1].ti-jl(i))%2) {fl=1,puts("No");break;}
		}
		if(!fl) puts("Yes");
	}
	return 0;
}
