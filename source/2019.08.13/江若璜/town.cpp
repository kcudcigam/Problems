#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=300005;
ll n,fa[N],maxn[N],sec[N],thi[N],cnt[N][3],len[N],grand[N];
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
ll search(ll x,ll y,ll z,ll last){
	if(cnt[x][0]==last){
		if(z>maxn[x]) maxn[x]=z,cnt[x][0]=last;
	}
	else if(cnt[x][1]==last){
		if(z>maxn[x]) sec[x]=maxn[x],maxn[x]=z,cnt[x][1]=cnt[x][0],cnt[x][0]=last;
		else if(z>sec[x]) sec[x]=z,cnt[x][1]=last;
	}
	else{
		if(z>maxn[x]) thi[x]=sec[x],sec[x]=maxn[x],maxn[x]=z,cnt[x][2]=cnt[x][1],cnt[x][1]=cnt[x][0],cnt[x][0]=last;
		else if(z>sec[x]) thi[x]=sec[x],sec[x]=z,cnt[x][2]=cnt[x][1],cnt[x][1]=last;
		else if(z>thi[x]) thi[x]=z,cnt[x][2]=last;
	}
	len[x]=max(len[x],max(maxn[x]+sec[x],y));
	if(fa[x]==x) return x;
	else return search(fa[x],len[x],z+1,x);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	rd(n);
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1,a,b;i<n;i++){
		rd(a);rd(b);
		fa[b]=a;
		if(cnt[a][0]==b){
			if(maxn[b]+1>maxn[a]) maxn[a]=maxn[b]+1,cnt[a][0]=b;
		}
		else if(cnt[a][1]==b){
			if(maxn[b]+1>maxn[a]) sec[a]=maxn[a],maxn[a]=maxn[b]+1,cnt[a][1]=cnt[a][0],cnt[a][0]=b;
			else if(maxn[b]+1>sec[a]) sec[a]=maxn[b]+1,cnt[a][1]=b;
		}
		else{
			if(maxn[b]+1>maxn[a]) thi[a]=sec[a],sec[a]=maxn[a],maxn[a]=maxn[b]+1,cnt[a][2]=cnt[a][1],cnt[a][1]=cnt[a][0],cnt[a][0]=b;
			else if(maxn[b]+1>sec[a]) thi[a]=sec[a],sec[a]=maxn[b]+1,cnt[a][2]=cnt[a][1],cnt[a][1]=b;
			else if(maxn[b]+1>thi[a]) thi[a]=maxn[b]+1,cnt[a][2]=b;
		}
		len[a]=max(len[a],max(maxn[a]+sec[a],maxn[b]+sec[b]));
		ll grand=(fa[a]==a?a:search(fa[a],len[a],maxn[b]+2,a));
		wr(len[grand]);puts("");
	}
	return 0;
}
