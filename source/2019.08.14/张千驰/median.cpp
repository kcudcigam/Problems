#include <iostream>
#include <cstdio>

using namespace std;

int n,m,a[500010],b[500010],op,x,y,z,l1,r1,l2,r2;

template <typename T> inline void read(T &n)
{
	n=0;char c;T sgn=1;
	for (c=getchar();!isdigit(c);c=getchar())
		if (c=='-')
			sgn=-1;
	for (;isdigit(c);c=getchar())
		n=(n<<1)+(n<<3)+(c^48);
	n*=sgn;
}

template <typename T> inline void write(T n)
{
	if (n<0) 
	{
		putchar('-');
		n=-n;
	}
	if (n>9)
		write(n/10);
	putchar(n%10+'0');
}

template <typename T> inline void writeln(T n)
{
	write(n);
	puts("");
}

inline void open_file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

inline int findkth(int a[],int m,int b[],int n,int k)
{
	if (m>n)
		return findkth(b,n,a,m,k);
	if (m==0)
		return b[k-1];
	if (k==1)
		return min(a[0],b[0]);
	int pa=min(k/2,m),pb=k-pa;
	if (a[pa-1]<b[pb-1])
		return findkth(a+pa,m-pa,b,n,k-pa);
	else if (a[pa-1]>b[pb-1])
			 return findkth(a,m,b+pb,n-pb,k-pb);
		 else
		 	 return a[pa-1];
}

int main()
{
	open_file("median");
	read(n),read(m);
	for (register int i=1;i<=n;++i)
		read(a[i]);
	for (register int i=1;i<=n;++i)
		read(b[i]);
	while (m--)
	{
		read(op);
		if (op&1)
		{
			read(x),read(y),read(z);
			if (x)
				b[y]=z;
			else 
				a[y]=z;
		}
		else
		{
			read(l1),read(r1),read(l2),read(r2);
			int len1=r1-l1+1,len2=r2-l2+1;
			writeln(findkth(a+l1,len1,b+l2,len2,(len1+len2)/2+1));
		}
	}
	return 0;
}
