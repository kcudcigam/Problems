#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000000;
const int luck_key=998244353;
long long a[200];

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,i;
	string s;
	cin>>n;
	cin>>s;
	a[0]=1;
	for(i=1;i<=n;i++){
		a[i]=(a[i-1]*26)%luck_key;
	}
	if(s.size()==n)cout<<(a[n]-1);
	else{
		
		
		
	}
	
	cout<<s.size()<<endl;
	
	
	return 0;
}


