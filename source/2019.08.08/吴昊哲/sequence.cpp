#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
    for (; isdigit(c);c=getchar()) x=x*10+c -'0';
    x*=f;
}
long long m,n,l,r,s,e,temp,ans;
long long sum[500000];
int main()
{
    //freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(l);read(r);read(s);read(e);
		if(s==e)
		{
			for(int i=l;i<=r;i++)
			{
				sum[i]+=s;
				
			}
		}
		if(s!=e)
		{
			temp=(e-s)/(r-l);
			for(int i=1;i<=r-l+1;i++)
			{
				sum[i]+=i*temp;
			}
		}
	}
	ans=sum[1];
	for(int i=2;i<=n;i++)
	{
		ans^=sum[i];
	}
	cout<<ans<<endl;
    return 0;
}
