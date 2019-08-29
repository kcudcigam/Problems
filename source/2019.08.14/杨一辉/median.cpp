#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,z,l1,l2,r1,r2,len1,len2,mi,fl;
int a[500005],b[500005];
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();
	m=ri();
	for(int i=1;i<=n;++i)a[i]=ri();
	for(int i=1;i<=n;++i)b[i]=ri();
	for(int i=1;i<=m;++i)
	{
		q=ri();
		if(q==1)
		{
			x=ri();
			y=ri();
			z=ri();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		if(q==2)
		{
			l1=ri();
			r1=ri();
			l2=ri();
			r2=ri();
			len1=r1-l1+1;
			len2=r2-l2+1;
			mi=(len1+len2)/2+1;
			for(int j=1;j<mi;++j)
			{
				if(l1>r1)
				{
					cout<<b[l2+mi-j-1]<<endl;
					fl=1;
					break;
				}
				if(l2>r2)
				{
					cout<<a[l1+mi-j]<<endl;
					fl=1;
					break;
				}
				if(a[l1]>b[l2])l2++;
				else l1++;
			}
			if(fl==0)
			{
				if(a[l1]>b[l2])cout<<b[l2]<<endl;
				else cout<<a[l1]<<endl;
			}
			else fl=0;
		}
	}
	return 0;
}

