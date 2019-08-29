#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],q,x,y,z,l1,r1,l2,r2,med;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
    read(n);read(m);
    for(register int i=1;i<=n;i++)
    read(a[i]);
    for(register int i=1;i<=n;i++)
    read(b[i]);
    
    
    for(register int i=1;i<=m;i++)
    {
    	read(q);
    	if(q==1) {
    		read(x);read(y);read(z);
    		if(x==0) a[y]=z;
    		else b[y]=z;
		}
		else
		{
			read(l1);read(r1);read(l2);read(r2);
			med=(r1-l1+r2-l2+2)/2;
			for(register int k=1;k<=med;k++)
			{
				if(l1>r1) l2++;
				else
				if(l2>r2) l1++;
				else
				if(a[l1]<b[l2]) l1++;
				else l2++;
			}
			if(l1>r1) cout<<b[l2]<<endl;
			else if(l2>r2) cout<<a[l1]<<endl;
			else
			if(a[l1]<b[l2]) cout<<a[l1]<<endl;
			else cout<<b[l2]<<endl;
		}
	}
    return 0;
 } 
 
  
