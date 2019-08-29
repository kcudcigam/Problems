#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &t)
{
	t=0; int flg=1,c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	if(c!='-') t=c-'0';
	else flg=-1;
	while(c=getchar(),'0'<=c&&c<='9') t=t*10+c-'0';
	t=t*flg;
}
template<typename T,typename... Args> inline void read(T &t,Args&... args) { read(t); read(args...); }
const int maxn=200005;
LL A,B,C,D,f[maxn];
int n,v[maxn],g[maxn];
inline LL cal(LL v) { return ((A*v+B)*v+C)*v+D; }
inline int Min(int i,int j)
{
	int res=0x3f3f3f3f;
	for(int k=i;k<=j;k++) res=min(res,v[k]);
	return res;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n,A,B,C,D);
	for(int i=1;i<=n;i++) read(v[i]);
	for(int i=1;i<=n;i++) f[i]=-1e14;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i]=max(f[i],f[j-1]+cal(Min(j,i)));
			printf("%lld ",f[j-1]+cal(Min(j,i)));
		}
		puts("");
	}
	printf("%lld\n",f[n]);
	return 0;
}
