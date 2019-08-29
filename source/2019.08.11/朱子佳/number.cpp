#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,n,s1,k,b,s2;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		s1=n%10;
		s2=-1;
		b=0;
		while(1){
			if(n<=10){
				if(s2==-1){
					b=1;
					break;
				}else{
					if(n==s1||n==s2){
						b=1;
						break;
					}else{
						b=0;
						break;
					}
				}
			}
			k=n%10;
			n/=10;
			if(k!=s1){
				if(s2==-1){
					s2=k;
				}else{
					b=0;
					break;
				}
			}
		}
		if(b==0){
			cout<<"2"<<endl;
		}else{
			cout<<"1"<<endl;
		}
	}
	return 0;
}

