#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 998244353
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=1e6+5;
int n,m;
int res=0;
char s[N];
//
inline int add(int x,int y){x+=y;return (x>=MOD)?x-MOD:x;}
inline int sub(int x,int y){x-=y;return (x<0)?x+MOD:x;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%MOD;}
inline int modpow(int x,ll y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=getint();
	scanf("%s",s);m=strlen(s);
	res=modpow(26,n);
	if(m==n){
		printf("%d\n",sub(res,1));
		return 0;
	}
	int val=modpow(26,n-m-1);
	for(int len=m;len>=0;len--){
		int tmp;
		if(len==m)tmp=mul(val,26);
		else tmp=mul(val,25);
		res=sub(res,tmp);
	}
	cout<<res<<endl;
	return 0;
}
