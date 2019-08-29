#include<bits/stdc++.h>
using namespace std;
int sum,k,n,m,x,y,a[100];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    cin>>n>>m;
    
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
	for (int i=1;i<=n;i++){
		cin>>x>>y;
	}
	k=n;
	for (int i=1;i<=5;i++){
		k=n;
		for (int j=1;j<i;j++){
			k=k*n;
		}
		k=k*a[i];
		
		sum+=k;
	}
	cout<<sum<<endl;
	return 0;
}


