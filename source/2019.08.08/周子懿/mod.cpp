#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int T;
const int N=11;
const int P=10e7+1;
int n[N];
ll p[N],f[P],ans[N];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init()
{
	read(T);
	for(int r=1;r<=T;r++)
	{
		read(n[r]);
		read(p[r]);
		f[1]=0;
		for(int i=2;i<=n[r];i++)
		{
			f[i]=((f[i-1]*i)%p[r]+((i-1)*i)%p[r]-(i%2==0)*(i/2-1)*2)%p[r];
		}
		ans[r]=f[n[r]];
		memset(f,0,sizeof(f));
	}
	for(int r=1;r<=T;r++)
	{
		cout<<ans[r]<<endl;
	}
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	init();
	return 0;
}

