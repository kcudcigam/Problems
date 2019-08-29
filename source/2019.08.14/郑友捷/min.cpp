#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,head,tail,cnt;
long long a,b,c,d;
inline long long f(long long x){
	return 1ll*(a*x*x*x+b*x*x+c*x+d);
}
int q[200010];
long long g[200010],sum[200010][20];
long long ans[200010],h[200010];
inline void pre(){
	int t=(int)log(n)/log(2)+1;
	for(register int i=1;i<=n;i++){
		for(register int j=0;j<t;j++){
			sum[i][j]=99999999999999;
		}
	}
	for(register int i=1;i<=n;i++){
		sum[i][0]=g[i];
	}
	for(register int j=1;j<t;j++){
		for(register int i=1;i<=n-(1<<j)+1;i++){
			sum[i][j]=min(sum[i][j-1],sum[i+(1<<(j-1))][j-1]);

		}
	}
}
inline long long query(int l,int r){
	if(l==0) l++;
	int k=log(r-l+1)/log(2);
	return min(sum[l][k],sum[r-(1<<k)+1][k]);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	for(register int i=1;i<=n;i++){
		scanf("%lld",&g[i]);
		ans[i]=-999999999999999;
	}
	ans[0]=0;
	pre();
	if(n<10000){
		for(register int i=1;i<=n;i++){
			for(register int j=0;j<i;j++){
				ans[i]=max(ans[i],ans[j]+f(query(j+1,i)));
			}
		}
		printf("%lld\n",ans[n]);
		return 0;
	}
	if(n>=10000){
		head=0,tail=1;
		q[++head]=0; 
		while(head<=tail){
			cnt++;
			long long maxx=-999999999999999;
			while(head<=tail&&query(q[tail]+1,cnt)>=g[cnt]){
				maxx=max(ans[q[tail]]+f(query(q[tail]+1,cnt)),maxx);
				tail--;
			}
			ans[cnt]=max(maxx,h[tail]);
			q[++tail]=cnt;
			h[tail]=max(ans[cnt],h[tail-1]);
		}
	}
	printf("%lld\n",ans[n]);
}
