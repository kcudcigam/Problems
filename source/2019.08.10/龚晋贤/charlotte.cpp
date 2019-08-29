#include<bits/stdc++.h>
using namespace std;
int t,i,j,k,n,a[200000],b[200000],c[200000],x,f;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    cin>>t;
    for (k=1;k<=t;k++)
    {
    	cin>>n;
    	a[0]=0; b[0]=0; c[0]=0;
    	f=0;
    	for (i=1;i<=n;i++)
    	cin>>a[i]>>b[i]>>c[i];
		for (i=1;i<=n;i++)
		{
			x=abs(b[i]-b[i-1])+abs(c[i]-c[i-1]);
			x=(a[i]-a[i-1])-x;
			if (x<0||x%2!=0) {
				cout<<"No"<<endl;
				f=1;
				break;
			}
		 } 
		 if (f==0) cout<<"Yes"<<endl;
	}
	return 0;
}


