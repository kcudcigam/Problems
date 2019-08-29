#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
#define mo 1000000007 
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
template<typename T> void chkmod(T &x,T y){x=(x+y)%mo;}
inline int lowbit(int x){return x&(-x);}
int n,X;
int dp1[10010];int dp[2][20010];
struct wzy{
	int a,b,c;
}co[1010];
inline bool cmp(wzy x,wzy y){
	return x.a>y.a;
}
inline int pos(int x){
	if(x<=X)return 1;
	x-=X;
	int l=1;int r=n;int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(co[mid].a>x){ans=mid;r=mid-1;}
		else{l=mid+1;}
	}
	return ans;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);

	read(n);read(X);
	rep(i,1,n){read(co[i].a);read(co[i].b);read(co[i].c);}
	sort(co+1,co+n+1,cmp);
	
	dp1[0]=1;
	rep(i,1,n){
		rep2(k,co[1].a,co[i].a){
			rep(j,1,co[i].c){
				if(j*co[i].a>k)break;
				chkmod(dp1[k],dp1[k-j*co[i].a]);	
			} 
		}
	}
	
	int t=1;dp[0][0]=dp[1][0]=1;
	rep(i,1,n){
		rep(j,1,X+co[1].a-1)dp[t][j]=dp[t^1][j];
		rep(j,1,X+co[i].a-1){
			rep(k,1,co[i].b){
				if(k*co[i].a>j)break;
				chkmod(dp[t][j],dp[t^1][j-k*co[i].a]);
			}
		}
		t^=1;
	}
	
	int ans=0;
	rep(i,X,X+co[1].a-1){
		int tmp=(1ll*dp1[i-X]*dp[t^1][i])%mo;
		chkmod(ans,tmp);
	}
	write(ans);
	return 0;
}
