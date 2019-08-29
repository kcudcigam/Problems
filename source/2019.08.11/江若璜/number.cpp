#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=300005;
ll n,t,cnt=1,f[20],tens[20],uset=1,usef,ans,now,v[20];
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
inline void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
bool check(ll x){
	memset(v,0,sizeof(v));
	ll y=0,xx=x;
	while(xx/=10) if(!v[xx%10]) y++,v[xx%10]=1;
	return y<3;
}
ll pw(ll x,ll y){
	ll sum=1,fl=x;
	while(y){
		if(y&1) sum=(sum*fl);
		fl=(fl*fl);y>>=1;
	}
	return sum;
}
void tr(){
	ans=min(ans,now);
//	cout<<ans<<' '<<now<<endl;
//	for(ll i=1;i<=usef;i++) cout<<f[i]<<endl;
	ll chucun=0,cando=0;
	for(ll i=1;i<=usef;i++)
		if(f[i]!=0)
			for(ll j=i+1;j<=usef;j++){
				if(f[j]!=0){
					if(f[i]==f[j]) f[i]+=f[j],chucun=f[j],f[j]=0,now--,cando=1,tr(),f[i]-=chucun,f[j]=chucun,now++;
				}
			}
	for(ll i=1;i<=usef;i++)
		if(f[i]!=0)
			for(ll j=i+1;j<=usef;j++){
				if(f[j]!=0){
					if(check(f[i]+f[j])) f[i]+=f[j],f[j]=0,now--,cando=1,tr(),f[i]-=chucun,f[j]=chucun,now++;
				}
			}
	if(cando) tr();
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rd(t);f[0]=tens[0]=1;tens[1]=10;
	while(t--){
		rd(n);
		if(check(n)){wr(1);puts("");continue;}
		memset(f,0,sizeof(f));f[0]=1;
		cnt=1;ans=10;ll noth=n;now=0;
		while(noth/=10) cnt++;
//		cout<<"----------"<<endl;
		if(cnt>uset){
			for(ll i=uset+1;i<=cnt;i++) tens[i]=tens[i-1]*10;
			uset=cnt;
		}
		for(ll i=1;i<=10;i++)
			for(ll j=0;j<cnt;j++) if((n/tens[j])%10>0) f[i]+=tens[j],n-=tens[j];
		for(ll i=1;i<=10;i++)
			if(f[i]>0) now++;
			else break;
		usef=now;
		tr();
/*		while(cando){
			cando=0;
			for(ll i=1;i<=usef;i++)
				if(f[i]!=0)
					for(ll j=i+1;j<=usef;j++){
						if(f[j]!=0){
							if(f[i]==f[j]) f[i]+=f[j],f[j]=0,now--,cando=1;
						}
					}
			for(ll i=1;i<=usef;i++)
				if(f[i]!=0)
					for(ll j=i+1;j<=usef;j++){
						if(f[j]!=0){
							if(check(f[i]+f[j])) f[i]+=f[j],f[j]=0,now--,cando=1;
						}
					}
		}*/
		if(n<=pw(10,13)) wr(min(ans,3LL)),puts("");
		else wr(ans),puts("");
	}
	return 0;
}
