#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
string s;int n;
long long hs(int x,int y){
	x%=Mod;
	long long sum=1;
	for(int i=1;i<=y;i++){
	sum*=x;sum%=Mod;}
	return sum%Mod;
}
long long same1(int l1,int l2){
	if(l1>2*l2){
		for(int i=1;i<=2*l2-l1+1;i++){
			if(s[i]!=s[l1-l2+i]){
				return l2-1;
			}
		}return l1-l2+1;
	}
	return hs(26,l1-2*l2);
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
    cin>>n;cin>>s;
    int t;t=s.length();
   // cout<<same1(n,t)<<endl;
    cout<<(hs(26,n)-((t+1)*hs(26,n-t)-same1(n,t)))%Mod;
    
    
	return 0;
}


