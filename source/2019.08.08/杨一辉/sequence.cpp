#include<bits/stdc++.h>
using namespace std;
long long a[500005],d[500005][2];
long long b,c,sum,l,r,s,e,n,m,flag,now;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(l);
		read(r);
		read(s);
		read(e);
		if(s==e)
		{
			flag++;
			d[l][0]+=s;
			d[r][1]+=e;
		}
		b=r-l;
		c=(e-s)/b;
		a[l]+=s;
		for(int j=1;j<=b;j++)
		{
			s+=c;
			a[l+j]+=s;
		}
	}
	if(flag!=m)
	for(int i=1;i<=n;i++)sum^=a[i];
	if(flag==m)
	{
		for(int i=1;i<=n;i++)
		{
			now+=d[i][0];
			now-=d[i-1][1];
			sum^=now;
		}
	}
	cout<<sum<<endl;
	return 0;
}
