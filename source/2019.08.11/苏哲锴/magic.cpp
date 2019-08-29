#include<bits/stdc++.h>

using namespace std;
int n;
const int Mod=998244353;
long long anss,su,ans_1;
bool sub1=true;
string s;
int sum(int x){
	
}

int jc(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
	}
	return ans;
}
int C(int x,int y){
	int ans=0;
	ans=jc(y)/(jc(x)*jc(y-x));
}

int main(){
freopen("magic.in","r",stdin);
freopen("magic.out","w",stdout);
cin>>n;
cin>>s;
int len=s.size();
for(int i=0;i<len;i++) {
	if(s[i]!='a') sub1=0;
}
if(sub1) {
	 su=pow(26,n);
	 su%=Mod;
	for(int j=len;j<=n;j++){
		anss+=C(j,n)%Mod*pow(25,(n-j));
	}
}
ans_1=(su-anss)%Mod;
if(sub1)cout<<ans_1<<endl;

	return 0;
}


