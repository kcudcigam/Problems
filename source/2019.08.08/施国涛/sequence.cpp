#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long xl[500000];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	for(int i=0;i<m;i++)
	{
		long long l,r,s,e;
		read(l);
		read(r);
		read(s);
		read(e);
		long long ch=(e-s)/(r-l);
		//cout<<ch;
		for(int i=l;i<=r;i++)
		{
			xl[i]+=s+ch*(i-l);
		}
	 } 
	 long long ans=xl[1];
	 for(int i=2;i<=n;i++)
	 {
	 //	cout<<xl[i]<<" ";
	 	ans^=xl[i];
	 }
	 cout<<ans;
}


