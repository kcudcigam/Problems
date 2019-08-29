#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int fa[300008],b[300008];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q,x,y,z,i,T,xx,yy,j;
	read(n);read(m);read(q);
	for (i=1;i<=n;i++)
	  fa[i]=i; 
	for (i=1;i<=m;i++)
	{
		read(x);read(y);
		z=fa[y];
		for (j=1;j<=n;j++)
		  if (z==fa[j]) fa[j]=fa[x];
	}
    for (i=1;i<=q;i++)
    {
    	read(T);
    	if (T==1) {
    		read(xx);read(yy);
    		for (j=1;j<=n;j++)
    		  if (fa[j]==fa[xx]) b[j]=b[j]+yy;
		}
		if (T==0)
		{
			int z;
			read(z);
			cout<<b[z]<<endl;
		}
    }
	return 0;
} 
