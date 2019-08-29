#include<bits/stdc++.h>
#pragma GCC optimize("Ofast","-ffast-math","-unroll-stack","-native=true")
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m,a[500001],b[500001];
int solve(int al,int ar,int bl,int br)
{
	int i=al;
	int j=bl;// 2 4 3 4
	int tot=(ar-al+br-bl+2)/2+1; //3
	int ans=0;
	while(1)
	{
		ans++;		
		if(ans==tot)
		{
			return (a[i]<b[j]?a[i]:b[j]);
		}
		a[i]<b[j]?++i:++j;		
		if(i>ar)
		{
			return b[j+tot-ans-1];
		}
		if(j>br)
		{
			return a[i+tot-ans-1];
		}
	}
 } 
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout); 
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		read(b[i]);
	}
	while(m--)
	{
		int op,x,y,z;
		read(op);
		read(x);
		read(y);
		read(z);
		if(op&1)
		{
				x?b[y]=z:a[y]=z;
		}
		else
		{
			int zr;
			read(zr);
			printf("%d\n",solve(x,y,z,zr));
		}
	}
 } 
