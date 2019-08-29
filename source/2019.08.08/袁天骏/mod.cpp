#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
#define iiii pair<int,pii >
#define INF 1000000000
#define MOD 1000000007
#define ll long long
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=1e7+5;
int f;
int n,mod;
//
void init(){
	f=0;
	for(register int i=2;i<=n/3;i++){
		register ll tmp=1ll*i*f;
		tmp+=1ll*i*(i-1);
		if(!(i&1))tmp-=(i-2);
		f=tmp%mod; 
	}
	for(register int i=n/3+1;i<=n/3*2;i++){
		register ll tmp=1ll*i*f;
		tmp+=1ll*i*(i-1);
		if(!(i&1))tmp-=(i-2);
		f=tmp%mod; 
	}
	for(register int i=n/3*2+1;i<=n;i++){
		register ll tmp=1ll*i*f;
		tmp+=1ll*i*(i-1);
		if(!(i&1))tmp-=(i-2);
		f=tmp%mod; 
	}
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int t=getint();
	rep(i,t){
		n=getint();mod=getint();
		init();
		cout<<f<<endl;
	}
	return 0;
}



