#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=1000010 ;
int jc[N];
int mul(int a,int b){
	a=a%mod;
	int ret=0;
	while(b){
		if(b&1)ret=(ret+a)%mod;
		a=(a*2)%mod;
		b/=2;
	}
	return ret;
}
int qmi(int di,int mi){
	di=di%mod;
	int ret=1;
	while(mi){
		if(mi&1)ret=mul(ret,di)%mod;
		di=mul(di,di)%mod;
		mi/=2;
	}
	return ret;
}
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n=read();
	string s_f,s_b;
	cin>>s_f;
	int Size=s_f.size(),bsize=0;
	int len=n-Size;
	int c=Size,Correct=0,tot=1;
	for(int i=1,cnt=1;i<=n-Size;i++){
		cnt=(cnt*26)%mod;
		jc[i]=cnt;
	}
	tot=qmi(26,n)%mod;
	for(;Size>=0;Size--){
		if(Size==c)Correct=(Correct+jc[Size])%mod;
		else Correct=(Correct+jc[Size])+(qmi(26,bsize)-1)%mod;
		bsize++;
	}
	cout<<tot-Correct<<endl;
	return 0;
}


