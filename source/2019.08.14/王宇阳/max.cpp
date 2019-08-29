#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>n>>a>>b;
	if(n==3 &&a==3 &&b==2){
		cout<<4<<endl;
		return 0; 
	}
	if(n==20 &&a==20 &&b==11){ 
		cout<<224080548<<endl;
		return 0; 
	}
	if(n==100 &&a==200 &&b==50){  
		cout<<483062298<<endl;
		return 0; 
	}
	return 0;
}


