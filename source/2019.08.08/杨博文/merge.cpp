#include<bits/stdc++.h>
using namespace std;
struct io{
	template <typename T> void read1(T &x){
		int f=1;x=0;char c=getchar();
		for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
		for (; isdigit(c);c=getchar()) x=x*10+c -'0';
		x*=f;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
const int maxn=1*1e6+100;
int n,q;
int f[maxn],r[maxn],sum[maxn];
int fa(int x)
{
	if(x==f[x])return x;
	return fa(f[x]);
}
int goo(int x)
{
	if(x==f[x])return sum[x];
	return sum[x]+goo(f[x]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	yin>>n>>q;
	for(int i=1;i<=n;i++)f[i]=i;
	while(q--)
	{
		int t,x,y;
		yin>>t>>x>>y;
		if(t==1)
		{
			int sx=fa(x),sy=fa(y);
			if(sx!=sy)
			{
				if(r[sx]<r[sy])
				{
					f[sx]=sy;
					sum[sx]-=sum[sy];
				}
				else
				{
					f[sy]=sx;
					sum[sy]-=sum[sx];
					if(r[sx]==r[sy])++r[sx];
				}
			}
		}
		else
		{
			int sx=fa(x);
			sum[sx]+=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",goo(i));
	}
	return 0;
}
