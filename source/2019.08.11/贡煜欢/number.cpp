#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1005],tot[100005];
int s[10000];
long long zxy(long long x)
{
	long long j=0,i,sum=0;
	while (x!=0)
    {
    	j++;
    	s[j]=x%10;
    	x=x/10;
	}
	sort(s+1,s+j+1);
	s[j+1]=-1;
	for (i=2;i<=j+1;i++)
	  if (s[i]!=s[i-1]) sum++;
	return sum;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    long long  i,j,n,k=0;
   cin>>n;
    for (i=1;i<=n;i++)
      cin>>a[i];
	for (i=1;i<=n;i++)
	  if (zxy(a[i])<=2) cout<<1<<endl;
	    else {
	    	bool f=0;
	    	for (j=1;j<=a[i]/2;j++)
	    	  if (zxy(j)<=2&&zxy(a[i]-j)<=2)
	    	    f=1;
	    	if (f==1) cout<<2<<endl;
	    	  else cout<<3<<endl;
		} 
	return 0;
}


