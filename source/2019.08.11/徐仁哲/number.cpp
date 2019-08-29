#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		while(s.find("0")!=0){
			s[s.find("0")]+=10;
			s[s.find("0")-1]-=1;
		}
		
	}
	return 0;
}
