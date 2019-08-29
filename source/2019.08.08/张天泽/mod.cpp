#include<bits/stdc++.h>
using namespace std;
long long n,p,q;
long long f[100000];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>q;
  	for (int j=1;j<=q;j++)
  		  {
  		  	cin>>n>>p;
			 f[1]=0; 
  			for (int i=2;i<=n;i++)
  			{
  				f[i]=(f[i-1]*i+i*(i-1))%p;
  				if (i%2==0) f[i]=(f[i]-i+2+p)%p;
			  }
  			cout<<f[n]<<endl;
		  }
	return 0;
}


