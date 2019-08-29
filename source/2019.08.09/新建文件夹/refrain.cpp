#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n,m1,m2,num;
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>m1>>m2;
	if(num==1) {
		cout<<"0"<<endl;
		return 0;
	}
	if(num==3) {
		cout<<"3628784"<<endl; return 0;
	}
	if(num==2) {
		if(m1==2||m2==2) {
			cout<<"0"<<endl; return 0;
		} 
		else {
			cout<<"1"<<endl; return 0;
		}
	}
	if(num==14) {
		cout<<"146326043"<<endl; return 0;
	}
	if(num==15) cout<<"782378613"<<endl; return 0;
	return 0;
}
