#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T &t)
{
	t=0; int f=1,c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	if(c!='-') t=c-'0';
	else f=-1;
	while(c=getchar(),'0'<=c&&c<='9') t=t*10+c-'0';
	t=t*f;
}
template<typename T,typename... Args> inline void read(T &t,Args&... args) { read(t); read(args...); }
const int maxn=100005;
int T,n;
struct Data { int x,y,t; } a[maxn];
inline bool operator<(const Data &a,const Data &b) { return a.t<b.t; }
inline bool check()
{
	sort(a+1,a+1+n);
	int nx=0,ny=0,nt=0;
	for(int i=1;i<=n;i++)
	{
		int need=abs(a[i].x-nx)+abs(a[i].y-ny);
		if(need>a[i].t-nt) return 0;
		if((a[i].t-nt-need)&1) return 0;
		nt=a[i].t; nx=a[i].x; ny=a[i].y;
	}
	return 1;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while(T-->0)
	{
		read(n);
		for(int i=1;i<=n;i++) read(a[i].t,a[i].x,a[i].y);
		puts(check()?"Yes":"No");
	}
	return 0;
}
