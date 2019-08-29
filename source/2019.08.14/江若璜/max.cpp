#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=100005;
const ld mod=1e9+7;
ll n,m,q,l[N],r[N],minx[N];
struct stone{
	ll x,y,p;
}s[N];
ld ans;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
void dfs(ll step,ld gailv){
	if(step==n){
		ll sum=0;
		for(ll i=0,cnt=0;i<q;i++,sum+=cnt,cnt=0)
			for(ll j=l[i];j<=r[i];j++) cnt=max(cnt,minx[j]); 
		ans+=gailv*(ld)sum;
//		cout<<sum<<' '<<ans<<' '<<gailv<<endl;
		return ;
	}
	if(s[step].p==1){
		ll a=minx[s[step].x];
		if(a!=0) minx[s[step].x]=min(a,s[step].y);
		else minx[s[step].x]=s[step].y;
		dfs(step+1,gailv);
		minx[s[step].x]=a;
	} 
	else{
		dfs(step+1,gailv*(1.0-((ld)s[step].p)/mod));
		ll a=minx[s[step].x];
		if(a!=0) minx[s[step].x]=min(a,s[step].y);
		else minx[s[step].x]=s[step].y;
		dfs(step+1,gailv*((ld)s[step].p)/mod);
		minx[s[step].x]=a;
	}
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	rd(n);rd(m);rd(q);
	for(ll i=0,xx;i<n;i++){
		rd(s[i].x);rd(s[i].y);rd(s[i].p);
	}
	for(ll i=0;i<q;i++){
		rd(l[i]);rd(r[i]);
	}
	dfs(0,1.0);
	wr(round(ans));puts("");
	return 0;
}

