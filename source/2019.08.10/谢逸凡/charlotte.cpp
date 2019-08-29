#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
typedef long long ll;
using namespace std;
const int N=1e5+5;
int n,T;
bool flag;
struct pt{
	int x,y,t;
}d[N];
bool cmp(pt a,pt b){if(a.x==b.x) return a.y<b.y;return a.x<b.x;}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=ip();
	while(T--){
		n=ip();
		rep(i,1,n) d[i].t=ip(),d[i].x=ip(),d[i].y=ip();
		sort(d+1,d+1+n,cmp);
		rep(i,1,n){
			if((d[i].x-d[i-1].x)+abs(d[i].y-d[i-1].y)>d[i].t) {flag=1;break;}
		}
		if(!flag) puts("Yes");else puts("No");
	}
	return 0;
}


