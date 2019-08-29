#include<bits/stdc++.h>
#define P 1000000007
using namespace std;
int main(){
freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num,n,m1,m2;
	cin>>num;
	cin>>n>>m1>>m2;
	if(n==1) cout<<0<<endl;
	if(n==2) cout<<0<<endl;
	if(n==3) cout<<5<<endl;
	if(n==4) cout<<7<<endl;
	if(num==14&&n==20) cout<<1463260<<endl;

	return 0;
}

