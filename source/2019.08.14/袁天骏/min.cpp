#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
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
const int N=2e5+5;
int n,A,B,C,D,a[N];
const ll inf=2e18;
const int LOG=20;
ll dp[N],val[N];
int mn[LOG][N],lb[N],dq[N],dql[N],dqr[N];
vector<int>vx;
int BB;
//
inline ll calc2(int x){
	ll ans=0;
	ans+=1ll*A*x*x*x;
	ans+=1ll*B*x*x;
	ans+=1ll*C*x;
	ans+=1ll*D;
	return ans;
}
inline ll qry(int l,int r){
	int x=lb[r-l+1];
	//cout<<x<<" "<<mn[x][l]<<" "<<mn[x][r-(1<<x)+1]<<endl;
	return val[min(mn[x][l],mn[x][r-(1<<x)+1])];
}
inline ll calc(int x,int y){
	return dp[y]+qry(y+1,x);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=getint();A=getint();B=getint();C=getint();D=getint();
	for(int i=1;i<=n;i++){
		a[i]=getint();
		vx.push_back(a[i]);
	}
	if(!A&&!B&&C<=0){
		rep(i,n)val[i]=calc2(a[i]);
		bool flag=false;
		ll res=0;
		rep(i,n)if(val[i]>0){
			flag=true;
			res+=val[i];
		}
		if(!flag){
			res=-inf;
			rep(i,n)res=max(res,val[i]);
		}
		cout<<res<<endl;
	}
	sort(vx.begin(),vx.end());
	vx.resize(unique(vx.begin(),vx.end())-vx.begin());
	for(int i=1;i<=n;i++)a[i]=lower_bound(vx.begin(),vx.end(),a[i])-vx.begin();
	rep(i,vx.size())val[i]=calc2(vx[i]);
	for(int i=1;i<=n;i++)mn[0][i]=a[i];
	for(int i=1;i<LOG;i++)for(int j=1;j<=n;j++){
		if((1<<i)+j-1>n)break;
		mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	}
	lb[1]=0;
	for(int i=2;i<N;i++)lb[i]=lb[i>>1]+1;
	//cout<<qry(1,1)<<endl;
	int L=0,R=0;dq[L]=0;dql[L]=1;dqr[L]=n;
	BB=1000;
	if(n>1000)BB=500;
	for(int i=1;i<=n;i++){
		dp[i]=-inf;
		for(register int j=max(dq[L]-BB,0);j<=min(dq[L]+BB,i-1);j++){
			dp[i]=max(dp[i],calc(i,j));
		}
		if(dqr[L]<=i)++L;
		dql[L]=i+1;
	//	cout<<i<<" "<<dp[i]<<endl;
		if(calc(dqr[R],dq[R])>calc(dqr[R],i))continue;
		while(L<=R&&calc(dql[R],i)>calc(dql[R],dq[R]))--R;
		if(L>R){
			dq[++R]=i;
			dql[R]=i+1;
			dqr[R]=n;
			continue;
		}
		if(calc(dqr[R],dq[R]>calc(dqr[R],i))){
			dq[++R]=i;
			dql[R]=dql[R-1]+1;
			dqr[R]=n;
			continue;
		}
		int lb=dql[R],rb=dqr[R];
		while(rb-lb>1){
			int mid=(lb+rb)>>1;
			if(calc(mid,i)>calc(mid,dq[R]))rb=mid;
			else lb=mid;
		}
		dqr[R]=rb-1;
		dq[++R]=i;
		dql[R]=rb;
		dqr[R]=n;
	}
	cout<<dp[n]<<endl;
	return 0;
}
