#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define mo 998244353
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
char S[1000010];int f[1000010];int inv[1000010];
inline void P(){
	inv[1]=1;
	rep(i,2,1000000)inv[i]=(1ll*(mo-mo/i)*inv[mo%i])%mo;
	return;
}
inline int poww(int n,long long m){
	int ret=1;int temp=n;long long tmp=m;
	while(tmp){
		if(tmp&1)ret=(1ll*ret*temp)%mo;
		temp=(1ll*temp*temp)%mo;
		tmp>>=1;
	}
	return ret;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);

	P();
	long long n;read(n);scanf("%s",S+1);int s=strlen(S+1);
	
	if(n==1){f[1]=25;}
	else if(n==2){f[1]=625;}
	else{f[1]=(1ll*625*poww(26,n-2))%mo;}
	if(s==1){write(f[1]);return 0;}
	
	int dif=0;
	if(n==1){dif=0;}
	else if(n==2){dif=50;}
	else if(n==3){dif=1250;}
	else{dif=(1ll*1250*poww(26,n-3))%mo;}
	rep(i,2,s-1){
		f[i]=(f[i-1]+dif)%mo;dif=(1ll*dif*inv[i])%mo;
		dif=(1ll*dif*(i+1))%mo;dif=(1ll*dif*inv[26])%mo;
	}
	if(n==s){f[s]=(f[s-1]+s*25)%mo;}
	else{f[s]=(f[s-1]+dif)%mo;}
	write(f[s]);
	return 0;
}
