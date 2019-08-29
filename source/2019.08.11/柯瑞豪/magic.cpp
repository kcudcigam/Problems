#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,l,Ans;
string s;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
int power(int b){
	int ans=1%mod,a=26;
	for(;b;b>>=1){
		if(b&1)ans=(long long)ans*a%mod;
		a=(long long)a*a%mod;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();cin>>s;
	l=s.length();
	if(l==n){
		int Ans=(long long)power(n);
		Ans-=1;
		cout<<Ans<<endl;
		exit(0);
	}
	if(l==1){
		int Ans=(long long)power(n);
		Ans-=(long long)power(n-1)*2%mod;
		Ans+=power(n-2);
		Ans%=mod;
		cout<<Ans<<endl;
		exit(0);
	}
	bool flag=1;
	for(int i=0;i<l;i++)if(s[i]!='a'){flag=0;break;}
	if(flag){
		int d=n-l;
		int Ans=(long long)power(n);
		cout<<Ans<<endl;
		Ans-=(long long)power(d)*(l+1)%mod;
		Ans+=(l*(l+1))/2;
		cout<<Ans<<endl;
		exit(0);
	}
	return 0;
}
