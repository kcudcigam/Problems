#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,d;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long al[200005],ans;
signed main()
{
    freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);
	read(a);
	read(b);
	read(c);
	read(d);
	for(int i=1;i<=n;++i)
	{
		read(al[i]);
		al[i]=al[i]*al[i]*al[i]*a+al[i]*al[i]*b+al[i]*c+d;
		//cout<<al[i]<<" ";
	}
	long long mint=pow(2,62);
	for(int i=1;i<=n;i++)
	{
		if(al[i]>=0)
		{
			if(al[i+1]<0)
			{
				mint=al[i+1];
			}
			ans+=al[i];
		}
		else
		{
			if(al[i+1]>=0)
			{
				ans+=mint;
			}
			else
			{
				mint=min(mint,al[i+1]);
			}
		}
	}
	printf("%lld\n",ans);
 }
