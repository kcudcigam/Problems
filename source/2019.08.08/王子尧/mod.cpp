#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
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
int dp[10000010];

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);

	int q;read(q);
	rep(i,1,q){
		int n,p;read(n);read(p);
		dp[1]=0;dp[2]=2;
		rep(i,3,n){
			if(i%2==1){
				dp[i]=(1ll*i*dp[i-1])%p;
				dp[i]+=(1ll*i*(i-1))%p;dp[i]%=p;
			}else{
				dp[i]=(1ll*i*(dp[i-1]+1))%p;
				dp[i]+=(1ll*(i-1)*(i-2))%p;dp[i]%=p;
			}
		}
		write(dp[n]%p);
	}
	return 0;
}
