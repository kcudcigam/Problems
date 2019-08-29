#include<bits/stdc++.h>
using namespace std;
const int INF=998244353;
int n,l;
string s;
int Power(int b){
	int ans=1%INF,a=26;
	for(;b;b>>=1){
		if(b&1)ans=(long long)ans*a%INF;
		a=(long long)a*a%INF;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
   	cin>>s;
	l=s.length();
	if(l==n){
		printf("%d",Power(n)-1);
		return 0;
	}
	int a,b,ans;
	if(l==1){
		b=2*(Power(n-1))%INF;
		a=(Power(n-2))%INF;
		ans=Power(n)-b+a;
		printf("%d",ans);
	}
	if(l==2){
		b=3*(Power(n-2))%INF;
		a=(Power(n-2))%INF;
		if(n!=3)a+=(Power(n-3))%INF;
		ans=Power(n)-b+a;
	}
	return 0;
}


