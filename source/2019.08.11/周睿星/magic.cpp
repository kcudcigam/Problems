#include<bits/stdc++.h>
using namespace std;
long long tot=0;
long long power(int a,int b,int p){
	long long ans=1%p;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%p;
		a=a*a%p;
	}
	return ans;
}
long long read(){
	long long p=1,q=0;
	char ch=getchar();
	
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	//freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	long long n;
	n=read();
	string s;
	int Mod=998244353;
	getline(cin,s);
	long long sum=power(26,n,Mod);
	long long use=power(26,n-s.size(),Mod);
	for(int i=1;i<=(s.size()+1)/2;++i)
		tot=(tot+2*use-1)%Mod;
	cout<<sum-tot<<endl;
	return 0;
}

