#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
long long n,m;string s;
long long sum1=1,sum2=1;

bool check(string s){
    for(int i=1;i<m;i++)
      if(s[i]!=s[i-1])return false;
    return true;
}

long long power(ll a,ll b,ll p){
	ll sum=1;
	for(;b;b>>=1){
		if(b&1)sum=(sum*a)%p;
		a=a*a%p;
	}
	return sum;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
    scanf("%lld",&n);  sum1=power(26,n,Mod);  
	cin>>s;  m=(ll)s.length();   
	if(m==n){printf("%lld\n",sum1-1);return 0;}
	
    sum2=(m+1)*power(26,n-m,Mod)%Mod;  
    
	if(!check(s))if(n%m)printf("%lld\n",(ll)abs(sum1-sum2));
	if(!n%m||check(s))printf("%lld\n",(ll)abs(sum1-sum2+1));
	return 0;
}


