#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
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
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;} 
int n,A,B,C,D;
int co[200010];long long dp[200010];
inline long long f(int x){
	long long ret=0;
	ret+=A;ret*=x;ret+=B;ret*=x;ret+=C;ret*=x;ret+=D;
	return ret;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);

	read(n);read(A);read(B);read(C);read(D);
	rep(i,1,n)read(co[i]);
	
	dp[1]=f(co[1]);
	rep(i,2,n){
		int mi=co[i];dp[i]=dp[i-1]+f(mi);
		rep2(j,i-1,1){
			chkmin(mi,co[j]);
			chkmax(dp[i],dp[j-1]+f(mi));
		}
	}
	write(dp[n]);
	return 0;
}

