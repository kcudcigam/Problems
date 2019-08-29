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
int res;
const ll limit=1e13;
const int N=1e6+5;
int cnt;
ll a[105];
ll vs[N];
ll pw[20];
bool ok[15];
set<ll>S;
//
inline int calc(ll x){
	memset(ok,0,sizeof(ok));
	int ans=0;
	while(x){
		int y=x%10;
		if(!ok[y]){
			ans++;
			ok[y]=true;
		}
		x/=10;
	}
	return ans;
}
void dfs2(int x,ll y,int z,int w){
	//cout<<x<<endl;
	assert(y>=0);//cout<<y<<endl;
	if(x==14)return;
	S.insert(y);
	vs[cnt++]=y;y*=10;
	if(z==-1){
		rep(i,10)if(i)dfs2(x+1,y+i,i,w);
	}
	else if(w==-1){
		dfs2(x+1,y+z,z,w);
		rep(i,10)dfs2(x+1,y+i,z,i);
	}
	else{
		dfs2(x+1,y+z,z,w);
		dfs2(x+1,y+w,z,w);
	}
}
void init(){
	pw[0]=1;
	dfs2(0,0,-1,-1);
	sort(vs,vs+cnt);
	//cout<<cnt<<endl;
}
void dfs(ll x,int y){
	//cout<<y<<" "<<res<<endl;
	if(y>=res)return;
	if(!x){res=y;return;}
	if(y>=res-1)return;
	rep(i,cnt){
		if(vs[i]>x)break;
		dfs(x-vs[i],y+1);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	//rep(i,10)cout<<vs[i]<<endl;
	int t=getint();
	ll mx=0ll;
	rep(i,t)cin>>a[i],mx=max(mx,a[i]);
	if(mx<=limit){
		rep(i,t){
			res=3;
			if(calc(a[i])<=2)cout<<1<<endl;
			else{
				dfs(a[i],0);
				cout<<res<<endl;
			}
		}
	}
	else{
		rep(i,t){
			res=9;
			if(calc(a[i])<=2)cout<<1<<endl;
			else{
				dfs(a[i],0);
				cout<<res<<endl;
			}
		}
	}
	return 0;
}
