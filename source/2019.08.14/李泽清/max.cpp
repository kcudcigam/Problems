#include<bits/stdc++.h>
#define LL long long
#define pa pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int Mod=1000000007;
const int N=100010;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
vector<pa> v[N],q;
vector<LL> w[N];
int n,m,Q;
LL an[N],ans;
int ll[N];
LL Pow(LL x,LL bs){
	LL an=1;
	for(;bs;bs>>=1,x=x*x%Mod)
		if(bs&1)an=an*x%Mod;
	return an;
}
bool cmp(pa a,pa b){return a.fi>b.fi;}
void Solve(int l,int r){
	q.clear();
	F(i,l,r)
		for(auto j:v[i])q.push_back(mp(j.fi,i));
	sort(q.begin(),q.end(),cmp);
	LL now=1;
	F(i,l,r)an[i]=1;
	F(i,l,r)ll[i]=w[i].size()-1;
	for(auto ii:q){
		int p=ii.se;
		now=now*Pow(an[p],Mod-2)%Mod;
		ans+=w[p][ll[p]]*now%Mod*ii.fi%Mod;
		//cerr<<w[p][ll[p]]<<' '<<now<<'\n';
		an[p]=(an[p]+Mod-w[p][ll[p]])%Mod;
		now=now*an[p]%Mod;
		--ll[p];
		//cerr<<an[p]<<'\n';
	}
	ans%=Mod;
	//cerr<<ans<<'\n';
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=R();m=R();Q=R();
	while(m--){
		int x=R(),y=R(),p=R();
		v[x].push_back(mp(y,p));
	}
	F(i,1,n)sort(v[i].begin(),v[i].end());
	F(i,1,n){
		LL now=1;
		for(auto j:v[i]){
			w[i].push_back(now*j.se%Mod);
			//cerr<<now*j.se%Mod<<'\n';
			now=now*(1+Mod-j.se)%Mod;
		}
	}
	while(Q--){
		int l=R(),r=R();
		Solve(l,r);
	}
	cout<<ans<<'\n';
	return 0;
}
