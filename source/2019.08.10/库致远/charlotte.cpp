#include<bits/stdc++.h>
using namespace std;
int sum,tt,xb,yb,y,x,t,n,sum_z,tb,s;
int main(){
  freopen("charlotte.in","r",stdin);
  freopen("charlotte.out","w",stdout);
  cin>>tt;
  for (int g=1;g<=tt;g++){
  	t=x=y=0;
  	cin>>n;
  	s=0;
  	for (int i=1;i<=n;i++){
  		cin>>t>>x>>y;
  		sum=abs(x-xb)+abs(y-yb);
  		sum_z=t-tb;//可走的时间 
  		if (sum_z<sum) {
  			cout<<"No"<<endl;
  			s=1;
  			break;
		  }
		  if (sum_z==sum) {
  			xb=x;yb=y;tb=t;
  		
		  }
		  if ((sum_z-sum)%2==0) {
  		
  			xb=x;yb=y;tb=t;
  			
		  }
		  if ((sum_z-sum)%2==1) {
  			cout<<"No"<<endl;
  			s=1;
  			break;
		  }
	  }
	  if (s==0) cout<<"Yes"<<endl;
  }
	return 0;
}


