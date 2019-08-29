#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=305,M=10000005;
ll n,m,s1,s2,s3,s4,s5,l[N],r[N],ans,v[M],id[N],maxn,use[N],cntuse,sum;
bool r1=true;
template <typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>9) write(x/10),putchar(x%10+'0');
}
ll pw(ll x,ll y){
	if(y==0) return 1;
	ll sum=1,f=x;
	while(y){
		if(y&1) sum*=f;
		f*=f;y>>=1;
	}
	return sum;
}
bool cmp(ll x,ll y){
	return r[x]<r[y]||r[x]==r[y]&&l[x]<l[y];
}
void sub1(){
	if(s1>0) ans+=n*s1;
	if(s2>0) ans+=pw(n,2)*s2;
	if(s3>0) ans+=pw(n,3)*s3;
	if(s4>0) ans+=pw(n,4)*s4;
	if(s5>0) ans+=pw(n,5)*s5;
	write(ans);puts("");
}
ll jisuan(ll x){
	ll ss=0;
	if(s1>0) ss+=x*s1;
	if(s2>0) ss+=pw(x,2)*s2;
	if(s3>0) ss+=pw(x,3)*s3;
	if(s4>0) ss+=pw(x,4)*s4;
	if(s5>0) ss+=pw(x,5)*s5;
	return ss;
}
void tr(){
	cout<<cntuse<<' '<<sum<<endl;
	ans=max(ans,sum);
	if(cntuse==n) return ;
	queue<ll> q;
	for(ll i=1,now=0;i<=m;i++){
			now+=v[i];
			if(now>maxn){
				while(!q.empty()) q.pop();
				maxn=now;q.push(i);
			}
			else if(now==maxn) q.push(i);
		}
		while(!q.empty()){
			ll a=q.front();q.pop();
			ll biaoji[N]={0},th=0;
			for(ll i=n-1;i>=0;i--){
				if(r[id[i]]<a) break;
				if(l[id[i]]<=a&&!use[i]){
					use[i]=1;
					biaoji[i]=1;
					v[l[id[i]]]--;
					v[r[id[i]]]++;
					cntuse++;th++;
				}
			}
			sum+=jisuan(th);
			tr();
			cntuse-=th;
			for(ll i=n-1;i>=0;i--){
				if(r[id[i]]<a) break;
				if(biaoji[i]){
					v[l[id[i]]]++;
					v[r[id[i]]]--;
				}
			}
		}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);read(s1);read(s2);read(s3);read(s4);read(s5);
	for(ll i=0;i<n;i++) id[i]=i;
	for(ll i=0;i<n;i++){
		read(l[i]);read(r[i]);v[l[i]]++;v[r[i]-1]--;
		if(l[i]!=1||r[i]!=m) r1=false;
	}
	if(s2==0&&s3==0&&s4==0&&s5==0){write(n*s1);puts("");}
	else if(r1) sub1();
	else{
		tr();
		write(ans);puts("");
	}
	return 0;
}
