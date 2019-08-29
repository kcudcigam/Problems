#include<bits/stdc++.h>
using namespace std;
int	med,n,m,a[500005],b[500005],mid[1000005],ans; 
int c,x,y,z,l1,r1,l2,r2,w,v,s,d;
int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int i,j,k;
	n=ri();
	m=ri();
	for(i=1;i<=n;i++)	a[i]=ri();
	for(i=1;i<=n;i++)	b[i]=ri();
	for(i=1;i<=m;i++)
	{
		c=ri();
		if(c==1)
		{
			x=ri();
			y=ri();
			z=ri();
			if(x==0) a[y]=z;
			else b[y]=z;
		}if(c==2)
		{
			ans=0;
			v=0;
			l1=ri();r1=ri();l2=ri();r2=ri();
			med=((r1-l1)+r2-l2+2)/2+1;
			for(j=l1;j<=r1;)
			{
				for(k=l2;k<=r2;)
				{
					if(a[j]<b[k])
					{
						ans++;
						j++;
						v=0;
					}
					else
					{
						ans++;
						k++;
						v=1;
					}
					if(ans==med)
					{
						s=j;
						d=k;
						break;	
					}	
				}
			}
			if(v==0)
			{
				mid[++w]=a[s-1];
			}
			if(v==1)
			{	
				mid[++w]=b[d-1];
			}
		}
	}
	for(i=1;i<=w;i++)
	{
		cout<<mid[i]<<endl;
	}
	return 0;
}
/*5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4*/
