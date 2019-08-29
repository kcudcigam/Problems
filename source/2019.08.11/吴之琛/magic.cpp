#include<bits/stdc++.h>
#define ll long long
#define Mod 998244353
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
ll n;
ll tot,ans;
string s;
bool isabc(char ch){
	return (ch>='a')&&(ch<='z');
}
ll poww(int y){
	ll res=1,x=26;
	while (y){
		if (y&1) res=(res*x)%Mod;
		x=(x*x)%Mod;
		y>>=1;
	}
	return res;
}
ll count(int x){
	ll tmp=26;
	ll k=x,tk=x+1;
	ll p1=poww(x-1);
	ll p2=(p1*tmp)%Mod;
	ll res1=(p2*tk)%Mod,res2=(p1*k)%Mod;
	res1-=res2;
	if (res1<0) res1+=Mod;
	return res1;
}
ll count2(int x){
	ll tmp=26;
	ll k=x,tk=x+1;int tn=n;
	ll p1=poww(tn-x-1);
	ll p2=(p1*tmp)%Mod;
	ll res1=(p2*tk)%Mod,res2=(p1*k)%Mod;
	res1-=res2;
	if (res1<0) res1+=Mod;
	return res1;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	char c=getchar();
	for (;!isabc(c);c=getchar());
	for (; isabc(c);c=getchar()) s+=c;
	if (s.length()==n){
		tot=poww(n);
		tot--;
		if (tot<0) tot+=Mod;
		printf("%lld\n",tot);
		return 0;
	}
	if (s.length()*2<=n){
		ans=poww(n-s.length()*2);
		ans=(ans*count(s.length()))%Mod;
		tot=poww(n);
		tot-=ans;
		if (tot<0) tot+=Mod;
		printf("%lld\n",tot);
		return 0;
	}
	tot=poww(n);
	ans=count2(s.length());
	tot-=ans;
	if (tot<0) tot+=Mod;
	printf("%lld\n",tot);
	return 0;
}

