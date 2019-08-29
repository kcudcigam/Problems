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
const int N=1e5+10;
int n,m,q;
vector<pii >v[N],a[N];
//
inline int add(int x,int y){x+=y;return (x>=MOD)?x-MOD:x;}
inline int sub(int x,int y){x-=y;return (x<0)?x+MOD:x;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%MOD;}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=getint();m=getint();q=getint();
	rep(i,m){
		int x=getint()-1;
		v[x].push_back(mp(getint(),getint()));
	}
	rep(i,n)sort(v[i].begin(),v[i].end());
	rep(i,n){
		int p=1;
		rep(j,v[i].size()){
			a[i].push_back(mp(v[i][j].first,mul(p,v[i][j].second)));
			p=mul(p,sub(1,v[i][j].second));
		}
		a[i].push_back(mp(0,p));
		sort(a[i].begin(),a[i].end());
	}
	if(q==n){
		rep(qqq,q){
			int x=getint()-1,y=getint()-1;
			int res=0;
			rep(j,a[x].size())res=add(res,mul(a[x][j].first,a[x][j].second));
			printf("%d\n",res);
		}
	}
	return 0;
}
