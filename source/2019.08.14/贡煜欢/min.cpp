#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
   int f=1;x=0;char c=getchar();
   for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
   for (; isdigit(c);c=getchar()) x=x*10+c-'0';
   x*=f;
}
int sum[200005],s[200005],mi[1005][1005],f[100000];
int main()
{
	freopen("min","r",stdin);
	freopen("min","w",stdout);
	int n,m,a,b,c,d,i,ma=-INT_MAX,j;
	read(n);
	read(a);
	read(b);
	read(c);
	read(d);
	for (i=1;i<=n;i++)
	{
	  read(sum[i]);
    }
    for (i=1;i<=n;i++)
    {
    	s[i]=i*i*i*a+i*i*b+i*c+d;
	}
    if (a==0&&b==0&&c<=0){
    	for (i=1;i<=n;i++) 
    	  ma=max(s[i],ma);
    	cout<<ma<<endl;
    	return 0;
	}
	for (i=1;i<=n;i++)
	{
		mi[i][i]=i;
    	for (j=i+1;j<=n;j++)
    	  if (sum[mi[i][j-1]]>sum[j]) mi[i][j]=j;
    	  else mi[i][j]=mi[i][j-1];
	}
	for (i=1;i<=n;i++)
	  for (j=i+1;j<=n;j++)
	    f[i]=max(f[i],f[j]+s[mi[j+1][i]]);
	cout<<f[n]<<endl;
	return 0;
}
