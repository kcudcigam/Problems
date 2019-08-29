#include<bits/stdc++.h>
using namespace std;
long long y,a[100];
int n,b[100000],c[100000],m,k;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
    cin>>y;
   if (y==1){
    	cout<<2<<" "<<1<<endl;
    	cout<<1<<" "<<2<<endl;
    	return 0;
	}
	if (y==2){
    	cout<<3<<" "<<3<<endl;
    	cout<<1<<" "<<2<<endl;
    	cout<<1<<" "<<3<<endl;
    	cout<<2<<" "<<3<<endl;
    	return 0;
	}
	if (y==3){
    	cout<<4<<" "<<5<<endl;
    	cout<<1<<" "<<4<<endl;
    	cout<<1<<" "<<2<<endl;
    	cout<<2<<" "<<4<<endl;
    	cout<<1<<" "<<3<<endl;
    	cout<<3<<" "<<4<<endl;
    	return 0;
	}
	if (y==4){
    	cout<<4<<" "<<6<<endl;
    	cout<<1<<" "<<4<<endl;
    	cout<<2<<" "<<3<<endl;
    	cout<<1<<" "<<2<<endl;
    	cout<<2<<" "<<4<<endl;
    	cout<<1<<" "<<3<<endl;
    	cout<<3<<" "<<4<<endl;
    	return 0;
	}
	if (y==5){
    	cout<<5<<" "<<8<<endl;
    	cout<<1<<" "<<5<<endl;
    	cout<<1<<" "<<2<<endl;
    	cout<<2<<" "<<5<<endl;
    	cout<<2<<" "<<3<<endl;
    	cout<<3<<" "<<4<<endl;
    	cout<<4<<" "<<5<<endl;
    	cout<<2<<" "<<4<<endl;
    	cout<<3<<" "<<5<<endl;
    	return 0;
	}
    a[2]=1;
    for (int i=3;i<=64;i++){
    	a[i]=a[i-1]*2;
    	if (a[i]>=y) {
            n=i;
			break;		
		}
	}
	m=n;
	m=m+n-3+y-a[n-1];

	cout<<n<<" "<<m<<endl;
	cout<<1<<" "<<n<<endl;
	cout<<1<<" "<<2<<endl;
	k=2;
		for (int i=2;i<n;i++){
	     cout<<i<<" "<<i+1<<endl;
	     k++;
	 }
	 if (k==m) return 0;
	 
	 for (int i=1;i<=n-2;i++){
	 	for (int j=i+2;j<=n;j++){
	 		if (i==1 && j==n) continue;
	 		cout<<i<<" "<<j<<endl;
	 		k++;
	 		if (k==m) return 0;
		 }
	 }
	return 0;
}

