#include<bits/stdc++.h>
using namespace std;
long long a[100008],b[100008];
bool cmp(long long x,long long y)
{
	return x>y;
 } 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    long long n,m,i,ans=0,max1=-INT_MAX,max2=-INT_MAX,j=0;
	cin>>n;
	for (i=1;i<=n;i++)
	  cin>>a[i];
	ans=0;
	a[n+1]=-1000000008;
	for (i=1;i<=n+1;i++) 
	{
		if (ans+a[i]>0) {ans=ans+a[i];max1=max(max1,ans);} 
		           else {
	                 j++;
	                 if (max1!=-INT_MAX) b[j]=max1;
		           	 ans=0;
		           	 max1=-INT_MAX;
				   }
	}
	sort(b+1,b+j+1,cmp);
	cout<<b[1]+b[2]<<endl;
	return 0;
}


