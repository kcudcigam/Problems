#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long n,m,l,r,s,e,gc,c,su[1000000],ss[1000000];
int main ()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	if (m<=1000&&n<=1000) 
	{
	for (int i=1;i<=m;i++)
	  {
	  	read(l);
		read(r);
		read(s);
		read(e); 
		gc=(e-s)/(r-l);
		for (int j=l;j<=r;j++)
		{
			su[j]+=s+gc*(j-l);
		}
	   } 
    }
    else
    {
    	for (int i=1;i<=m;i++)
    	{
	  		read(l);
			read(r);
			read(s);
			read(e); 
			if (s==e)
			ss[l]+=s;ss[r+1]-=s;
	    }
	    for (int i=1;i<=n;i++)
	    {
	    	su[i]=su[i-1]+ss[i];
		}
	}
	c=su[1];
	for (int i=2;i<=n;i++)
	  c=c^su[i];
	cout<<c<<endl;
    return 0;
}

