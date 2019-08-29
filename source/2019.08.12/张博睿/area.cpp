#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>x>>y;
	if(x<=1||y<=1){cout<<"infinity"<<endl;return 0;}
	if(x==y){cout<<"-1"<<endl;return 0;}
	if(x%4==3||y%4==3){cout<<5<<endl;return 0;}
	cout<<16<<endl;
	return 0;
}


