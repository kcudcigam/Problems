#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =2147483647;
inline int qread(){
	register int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=(ret<<3)+(ret<<1)+c-48; return ret*w;
}
const int MAXN =1e5+3,MOD=1e9+7;
struct Node {
	int x,y,p;
	bool operator <(const Node  x)const{return y<x.y;}
}P[MAXN];
struct Node_{
	int l,r;
	bool operator <(const Node_ x) const{return l<x.l;}
}Q[MAXN];
int p[MAXN],ans,n,m,q;
vector <pair<int,int> > v[MAXN],t;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	
	n=qread(),m=qread(),q=qread();
	up(1,m,i) P[i].x=qread(),P[i].y=qread(),P[i].p=qread();
	sort(P+1,P+1+m);
	up(1,m,i){
		LL PP=(LL)((LL)1-p[P[i].x]+MOD)*P[i].p%MOD;
		v[P[i].x].push_back(make_pair(P[i].y,PP));
		p[P[i].x]=((LL)p[P[i].x]+PP)%MOD;
	}
//	up(1,n,i) up(1,v[i].size(),j) printf("val:%d p:%d\n",v[i][j-1].first,v[i][j-1].second);
	up(1,q,i) Q[i].l=qread(),Q[i].r=qread();
	sort(Q+1,Q+1+q);
	up(1,q,i){
		t.clear(); int PPP=0;
		up(Q[i].l,Q[i].r,j) up(1,v[j].size(),k) t.push_back(make_pair(v[j][k-1].first,v[j][k-1].second));
		sort(t.begin(),t.end());
		dn(t.size(),1,i){
			int PP=(LL)((LL)1-PPP+MOD)*t[i-1].second%MOD;
			ans=((LL)ans+(LL)t[i-1].first*PP)%MOD;
			PPP=((LL)PPP+PP)%MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
/*
20 20 11
9 826322196 537969962
2 686889785 336377887
11 340328991 1
17 938917616 8595578
1 983070324 1
7 252098391 336068929
8 236193494 782079539
8 772834872 847016980
9 285411306 926660991
19 201895383 1
17 851623136 1
14 273527537 1
4 206948935 1
13 688587725 1
7 510001092 833552125
19 390272590 1
16 892707124 1
15 347439936 1
4 139065755 1
15 570267342 628568673
1 6
2 7
3 10
4 11
6 14
7 15
8 16
10 17
12 18
13 19
17 20

*/
