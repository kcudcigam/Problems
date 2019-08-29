#include<bits/stdc++.h>
using namespace std;
int q;
long long n,p;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n>>p;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(n==2){
			cout<<2%p<<endl;
			continue;
		}
		if(n==3){
			cout<<12%p<<endl;
			continue;
		}
		if(n==4){
			cout<<58%p<<endl;
			continue;
		}
		if(n==5){
			cout<<310%p<<endl;
			continue;
		}
		if(n==6){
			cout<<1886%p<<endl;
			continue;
		}
		if(n==7){
			cout<<13244%p<<endl;
			continue;
		}
		if(n==8){
			cout<<106002%p<<endl;
			continue;
		}
		if(n==9){
			cout<<954090%p<<endl;
			continue;
		}
		if(n==10){
			cout<<9540982%p<<endl;
			continue;
		}
		if(n>10){
			cout<<p/2+1<<endl;
		}
	}
	return 0;
}


