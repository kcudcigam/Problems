#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
long long i,n,m,j,k,A,B,C,D,Ql,Qr,Q,Max,M;
long long Min[MAXN*4],a[MAXN];
long long f[MAXN];
inline int read() 
{
	char c=getchar(); 
	int x=0,f=1; 
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline long long calc(long long N)
{
	return A*N*N*N+B*N*N+C*N+D;
}
inline void build(long long k,long long l,long long r)
{
	if (l==r)
	{
		Min[k]=a[l];return;
	}
	long long mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	Min[k]=min(Min[k*2],Min[k*2+1]);
}
inline long long query(long long k,long long l,long long r)
{
	if (l>Qr||r<Ql)
	return INT_MAX;
	if (l>=Ql&&r<=Qr)
	return Min[k];
	long long mid=(l+r)>>1;
	return min(query(k*2,l,mid),query(k*2+1,mid+1,r));
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin >> n >> A >> B >> C >> D;
	n=read();A=read();B=read();C=read();D=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
//		cin >> a[i];
	build(1,1,n);
	M=a[1];f[1]=calc(a[1]);
	for (int i=2;i<=n;i++)
	{
		M=min(M,a[i]);
		f[i]=calc(M);
	}
	for (register int i=2;i<=n;i++)
	{
		for (register int j=1;j<i;j++)
		{
			Ql=j+1;Qr=i;Q=query(1,1,n);
			f[i]=max(f[i],f[j]+calc(Q));
		}
	}
	cout << f[n] << endl;
	return 0;
}

