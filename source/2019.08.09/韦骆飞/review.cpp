#include<bits/stdc++.h>
using namespace std;
long long y,f[10000],p,o,p11,k[1000];
int main(){
    ios::sync_with_stdio(false);
    freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	f[2]=1;
	for (int i=2;i<=64;i++)
	  f[i+1]=2*f[i];
	p=2;
	while (f[p]<y)
	  p++;
	cout<<p<<" ";
	
	if (y==f[p]) 
	{
	  y=0;
	  cout<<p*(p-1)/2<<endl;
	  for (int i=1;i<=p;i++)
	  	for (int j=i+1;j<=p;j++)
	    	cout<<i<<" "<<j<<endl;
	    	return 0;
	  }
	y=y-f[p-1]-1;
	p--;
	o=1;
	while (y>0)
		{
			k[o+1]=y%2;
			y=y/2;
			o++;
		}
	for (int i=2;i<=o+1;i++)
	  p11+=k[o];
	p11+=(p-1)*p/2;
	cout<<p11<<endl;
	for (int i=1;i<=p;i++)
	  for (int j=i+1;j<=p;j++)
	    cout<<i<<" "<<j<<endl;
	cout<<1<<" "<<p+1<<endl;
	for (int i=1;i<=min(o+2,(long long)65);i++)
	  if (k[i]==1)
	  cout<<i<<" "<<p+1<<endl;
	cout<<p<<" "<<p+1<<endl;
	return 0;
}


