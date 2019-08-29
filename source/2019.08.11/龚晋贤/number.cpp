#include<bits/stdc++.h>
using namespace std;
long long t,i,k,n,a[10],s;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>t;
  for (k=1;k<=t;k++)
  {
  	cin>>n;
  	for (i=0;i<=9;i++)
  	a[i]=0;
  	while (n!=0) {
  		a[n%10]=1;
  		n=n/10;
	  }
	  s=0;
	  for (i=0;i<=9;i++)
	  if (a[i]==1) s++;
	  cout<<(s+1)/2<<endl;
  }
  return 0;
}


