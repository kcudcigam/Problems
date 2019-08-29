#include<bits/stdc++.h>
using namespace std;
int a[100100],n,m1,m2,m,sum,f[100100];
int kzy(int x,int y){
	f[x]=a[x];
	for (int i=x+1;i<=y;i++){
			if (a[i]+f[i-1]>a[i]) {
		f[i]=a[i]+f[i-1];
	  	  } 
		else {
		f[i]=a[i];
	         }
	}
	int ma=f[x];
	for (int i=x;i<=y;i++){
		if (ma<f[i]) ma=f[i]; 
	}
	return ma;
}
int main(){
  freopen("sum.in","r",stdin);
  freopen("sum.out","w",stdout);
  cin>>n;
  for (int i=1;i<=n;i++){
  	cin>>a[i];
  }
  for (int i=1;i<n;i++){
  	m1=kzy(1,i);
  	m2=kzy(i+1,n);
  	m=m1+m2;
  	if (m>sum) sum=m;
  }
  cout<<sum<<endl;
	return 0;
}


