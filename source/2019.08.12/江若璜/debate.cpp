#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=400005;
ll n,a1[N],a2[N],a[N],b11[N],b10[N],b01[N],b00[N],cnt11,cnt10,cnt01,cnt00,ans,v[N],b[N];
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	 if(x<0) putchar('-'),x=-x;
	 if(x<10) putchar(x+'0');
	 if(x>9) wr(x/10),putchar(x%10+'0');
}
bool cmp(ll x,ll y){
	return a[x]>a[y];
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	rd(n);
	for(ll i=0;i<n;i++){
		a1[i]=(ll)(getchar()-'0');
		a2[i]=(ll)(getchar()-'0');
		rd(a[i]);
		if(a1[i]==1&&a2[i]==1) b11[cnt11++]=i;
		else if(a1[i]==1&&a2[i]==0) b10[cnt10++]=i;
		else if(a1[i]==0&&a2[i]==1) b01[cnt01++]=i;
		else b00[cnt00++]=i;
		b[i]=i;
	}
	sort(b11,b11+cnt11,cmp);
	sort(b10,b10+cnt10,cmp);
	sort(b01,b01+cnt01,cmp);
	sort(b00,b00+cnt00,cmp);
	sort(b,b+n,cmp);
	for(ll i=0;i<cnt11;i++) ans+=a[b11[i]],v[b11[i]]=1;
	for(ll i=0;i<min(cnt10,cnt01);i++) ans+=a[b10[i]]+a[b01[i]],v[b10[i]]=v[b01[i]]=1;
	for(ll i=0,use=0;i<n&&use<cnt11;i++)
		if(!v[b[i]]) ans+=a[b[i]],use++;
	wr(ans);puts("");
	return 0;
}
