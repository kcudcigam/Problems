#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
char s[1000010];long long l;
long long quickpow(long long v,long long m){
	if(m==0)return 1;
	else if(m==1)return v;
	long long p=quickpow(v,m/2);
	if(m%2==0)return p*p%mod;
	else return p*p%mod*v%mod;
}
//dfs
long long cnt;
char d[110];
bool can(){
	int t=n-l+1;
	for(int i=1;i<=t;++i){
		bool flag=true;
		for(int j=i;j<=i+l-1 && flag;++j)
			if(d[j]!=s[j-i+1])flag=false;
		if(flag)return false;
	}
	return true;
}
void dfs(int x){
	if(x==n+1){
		if(can())cnt=(cnt+1)%mod;
		return;
	}
	for(int i=0;i<26;++i){
		d[x]=i+'a';
		dfs(x+1);
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld%s",&n,s+1);
	l=strlen(s+1);
	//特判1:字符串长度为1 
	if(l==1)
		cout<<quickpow(25,n)<<endl;
	//特判2:字符串长度与n相等 
	else if(l==n)
		cout<<(quickpow(26,n)-1+mod)%mod<<endl;
	//特判3:n<=4 
	else if(n<=100){
		dfs(1);
		cout<<cnt<<endl;
	}
	else return 0;
}
