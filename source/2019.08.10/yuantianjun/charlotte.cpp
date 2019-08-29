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
//
void solve(){
	int n=getint();
	bool res=true;
	int X=0,Y=0,T=0;
	rep(i,n){
		int t=getint()-T,x=getint(),y=getint();
		if(!res)continue;
		int len=abs(x-X)+abs(y-Y);
	//	cout<<len<<endl;
		if(len>t||(len&1)!=(t&1))res=false;
		T+=t;X=x;Y=y;
	}
	if(res)printf("Yes\n");
	else printf("No\n");
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t=getint();
	rep(i,t){
		solve();
	}
	return 0;
}
