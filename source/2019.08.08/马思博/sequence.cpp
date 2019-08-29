#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for (; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

long long a[500005];

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,l,r,s,e;
	read(n);read(m);
	while(m--)
	{
		read(l);read(r);
		read(s);read(e);
		//if(s==e) 
		//{
		//	a[l]+=s;
		//	a[r]-=s;
		//	continue;
		//}
		int c=(s+e)/(r-l+1);
		int b=s;
		for (int i=l;i<=r;++i) a[i]+=b,b+=c;
	}
	//for(int i=2;i<=n;i++) a[i]+=a[i-1];
	//for(int i=1;i<=n;i++) cout<<a[i]-a[i-1]<<" ";
	int ans=a[1]^a[2];
	for(int i=3;i<=n;i++) ans^=a[i];
	printf("%d",ans);
	return 0;
}
