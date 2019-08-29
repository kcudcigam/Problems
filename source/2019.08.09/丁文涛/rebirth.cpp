#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const LL  INF=LLONG_MAX;
const int SIZ= 1e3;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int ret,w,c;
	while((c=readc())>'9'||c<'0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret;
}
const int MAXN =2e5,MAXM=10e5;
int num,n,m ;LL dis[MAXN],dis_[MAXN],val[MAXM*2];
int tot,head[MAXN],ver[MAXM*2],nxt[MAXM*2];
void add(int u,int v,LL w){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot,val[tot]=w;
}
void dijstra(){
	priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		LL u=pq.top().second,w=pq.top().first; pq.pop();
		if(dis[u]!=INF) dis_[u]=min(dis_[u],w); else{
			dis[u]=w;
			for(int i=head[u];i;i=nxt[i]){
				int v=ver[i];
				pq.push(make_pair(w+val[i],v));
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	
	num=qread(),n=qread(),m=qread();
	up(1,n,i) dis[i]=dis_[i]=INF; dis_[1]=0;
	up(1,m,i){
		int u=qread(),v=qread(),w=qread();
		if(u==v) continue;
		add(u,v,w),add(v,u,w);
	}
	dijstra();
	up(1,n,i) printf("%lld ",(dis_[i]==INF)?-1:dis_[i]);
	return 0;
} 
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1


*/
