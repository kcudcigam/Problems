#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
const int P=1000010;
int n,m,a[N],f[P],b[P],c[P];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init()
{
	read(n);read(m);
	for(int i=1;i<=n;i++)	
		read(a[i]);
}
void work()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j>=a[i])f[j]=max(b[j],c[j-a[i]]+1);
			else f[j]=b[j];
		}
		if(i==n){
			cout<<f[m]<<endl;
			return;
		}
		for(int j=1;j<=m;j++)
		{
			c[j]=b[j];
			b[j]=f[j];
		}
	}
}
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	init();
	work();
	return 0;
}


