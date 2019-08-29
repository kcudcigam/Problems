#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define go(i,u) for(int i=head[u];i;i=nex[i]
using namespace std;
typedef long long ll;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=5e5+10;
int n,m,opt,x,y,z,l1,l2,r1,r2;
int a[N],b[N];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n),read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,n)
	{
		read(opt);
		if(opt==1)
		{
			read(x),read(y),read(z);
			if(!x)a[y]=z;
			else b[y]=z;
		}
		else
		{
			read(l1),read(r1),read(l2),read(r2);
			int x=(r1-l1+1+r2-l2+1)/2;
			rep(j,1,x)
			{
				if(l1>r1)
				l2++;
				else 
				if(l2>r2)
				l1++;
				else
				if(a[l1]<b[l2])
				l1++;
				else l2++;
			}
			if(l1>r1)
			printf("%d\n",b[l2]);
			else 
			if(l2>r2)
			printf("%d\n",a[l1]);
			else
			if(a[l1]<b[l2])
			printf("%d\n",a[l1]);
			else printf("%d\n",b[l2]);
		}
	}
	return 0;
}



