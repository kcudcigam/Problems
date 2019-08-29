#include<bits/stdc++.h>
using namespace std;
int Y;
int cnt;
int t=0;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	if(Y==1){
	cout<<2<<" "<<1<<endl;
	cout<<1<<" "<<2<<endl;}
    if(Y==2) 
    {
    	cout<<3<<" "<<3<<endl;
    	cout<<1<<" "<<2<<endl;
    	cout<<1<<" "<<3<<endl;
    	cout<<2<<" "<<3<<endl;
    	
	}
	else if(Y<1024) {
		cout<<Y+1<<" "<<2*Y-1<<endl;
		for(int i=2;i<=Y;i++){
			cout<<1<<" "<<i<<endl;
			cout<<i<<" "<<Y+1<<endl;
			
		}
		cout<<1<<" "<<Y+1<<endl;
	}
	else if(Y>=1024){
		while(Y%2==0) 
	{
		Y/=2;
		cnt++;
		}
		cout<<2+2*cnt<<" "<<4*cnt<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		while(++t<cnt){
			
			cout<<2*t<<" "<<2*t+2<<endl;
			cout<<2*t+1<<" "<<2*t+2<<endl;
			cout<<2*t<<" "<<2*t+3<<endl;
			cout<<2*t+1<<" "<<2*t+3<<endl;
			
		}
		cout<<2*cnt<<" "<<2+2*t<<endl;
		cout<<2*cnt+1<<" "<<2+2*t<<endl;
	}
	
	return 0;
}

