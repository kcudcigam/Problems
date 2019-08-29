#include<bits/stdc++.h>
using namespace std;
long long a[500008];
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
  for (; isdigit(c);c=getchar()) x=x*10+c-'0';
  x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    long long n,m,i,l,r,s,e,k,j,ans=0;
    read(n);
    read(m);
    for (i=1;i<=m;i++)
    {
    	long long sum=0;
    	read(l);
    	read(r);
    	read(s);
    	read(e);
    	k=(e-s)/(r-l);
    	sum=s;
    	for (j=l;j<=r;j++)
    	{
    	  a[j]=a[j]+sum;
		  sum=sum+k;	
		}
    }
    long long z=a[1];
	for (i=2;i<=n;i++)
	{
		z=z^a[i];
	  }  
	cout<<z<<endl;
	return 0;
}


