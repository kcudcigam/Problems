#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll n,m,a[N+N],id[N+N],xiugai=1;
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
bool cmp(ll x,ll y){
	return a[x]<a[y];
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	rd(n);rd(m);
	for(ll i=1;i<=n+n;i++) rd(a[i]),id[i]=i;
	for(ll u=0,x,y,z,c,l1,r1,l2,r2;u<m;u++){
		rd(c);
		if(c==1){
			rd(x);rd(y);rd(z);
			ll w=0;
			if(x==0) a[y]=z,w=y;
			else a[y+n]=z,w=y+n;
			if(!(z>=a[id[w]-1]&&z<=a[id[w]+1])) xiugai=1;
		}
		else{
			rd(l1);rd(r1);rd(l2);rd(r2);
			ll cnt=0,ans=0;
			if(xiugai){sort(id+1,id+n+n+1,cmp);xiugai=0;}
			for(ll i=1;i<=n+n;i++){
				if(l1<=id[i]&&r1>=id[i]||l2+n<=id[i]&&r2+n>=id[i]) cnt++;
				if(cnt==(r2+r1-l1-l2+3)/2){ans=a[id[i]];break;}
			}
			wr(ans);puts("");
		}
	}
	return 0;
}
