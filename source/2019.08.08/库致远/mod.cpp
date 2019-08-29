#include<bits/stdc++.h>
using namespace std;
int n,b,c,a[1000000],k;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
    a[1]=0;
	a[2]=2;
	a[3]=12;
	a[4]=58;
	a[5]=310;
	a[6]=1886;
	a[7]=13244;
	a[8]=106002; 
	a[9]=954090;
	a[10]=9540982;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>c>>b;
		k=a[c]%b;
		cout<<k<<endl;
	}
	return 0;
}


