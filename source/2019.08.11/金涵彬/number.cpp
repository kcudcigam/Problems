#include<bits/stdc++.h>
using namespace std;
bool check(int s){
	int a,b;
	int t=0;
	while(s){
		if(t==0){
			t++;
			a=s%10;
		}else{
			if(t==1){
				if(s%10==a);
				else {
					t++;
					b=s%10;
				}
			}else{
				if(s%10!=a&&s%10!=b){
					return false;
				}
			}
		}
		s/=10;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(check(n)){
			cout<<1<<endl;
		}else{
			bool th=true;
			for(int j=1;j*2<=n;j++){
				if(check(j)&&check(n-j)){
					cout<<2<<endl;
					th=false;
					break;
				}
			}
			if(th){
				cout<<3<<endl;
			}
		}
	}
	return 0;
}


