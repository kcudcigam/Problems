#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
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
const int maxn=500005;
const int maxm=1000005;
const int oo=0x3f3f3f3f;
int n,m,a[maxn],b[maxn],op,x,y,z,L1,R1,L2,R2;
inline int f(int v,int L,int R,int p)
{
	if(p<L) return -oo;
	if(p>R) return oo;
	return v;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	a[0]=b[0]=oo;
	for(int i=1;i<=m;i++)
	{
		read(op);
		if(op==1)
		{
			read(x,y,z);
			if(x==0) a[y]=z;
			else b[y]=z;
			continue;
		}
		read(L1,R1,L2,R2);
		int len=R1-L1+1+R2-L2+1,sm=len/2;
		int L=L1,R=R1,M,p1=0,p2=0;
		while(L<=R)
		{
			M=(L+R)>>1;
			int tot=M-L1;
			tot=sm-tot;
			if(f(b[L2+tot-1],L2,R2,L2+tot-1)<=a[M]&&a[M]<=f(b[L2+tot],L2,R2,L2+tot)) { p1=M; break; }
			if(f(b[L2+tot],L2,R2,L2+tot)>a[M]) L=M+1;
			else R=M-1;
		}
		L=L2; R=R2;
		while(L<=R)
		{
			M=(L+R)>>1;
			int tot=M-L2;
			tot=sm-tot;
			if(f(a[L1+tot-1],L1,R1,L1+tot-1)<=b[M]&&b[M]<=f(a[L1+tot],L1,R1,L1+tot)) { p2=M; break; }
			if(f(a[L1+tot],L1,R1,L1+tot)>b[M]) L=M+1;
			else R=M-1;
		}
		printf("%d\n",min(a[p1],b[p2]));
	}
	return 0;
}
