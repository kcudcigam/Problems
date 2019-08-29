#include<bits/stdc++.h>
using namespace std;

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
	int n,m;
	long long ans=0;
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		int l,r,x,y;
		read(l);read(r);read(x);read(y);
		if (x==y) 
		{
			if ((r-l+1)%2==1) ans=ans^x;
			continue; 
		}
		int h=(y-x)/(r-l);
		int k=-1; 
		for (int j=l;j<=r;j++)
		{
			k++;
			int v=x+k*h;
			ans=ans^v;
		}
	}
	cout<<ans<<endl;
	return 0;
}


