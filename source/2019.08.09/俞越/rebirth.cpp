#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5050,E=1e6+10;
int head[M],nxt[E],to[E],w[E],cnt;
//int X[E],Y[E],W[E];
int n,m;
void add(int x,int y,int v){
	nxt[++cnt]=head[x]; head[x]=cnt; to[cnt]=y; w[cnt]=v;
}
LL dis[M],inf;
LL diss[M];
bool vis[M];
void dij(int del){
	priority_queue<pair<LL,int> > q;
	q.push(make_pair(0,1)); ms(vis,0); ms(dis,1); inf=dis[1]; dis[1]=0;
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=nxt[i]){	
//			cout<<x<<" "<<vis[x]<<" GG\n";
			if (i==del || i==(del^1)) continue;
			int y=to[i];
			if (dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
void dijj(int del){
	priority_queue<pair<LL,int> > q;
	q.push(make_pair(0,1)); ms(vis,0); ms(diss,1); inf=diss[1]; diss[1]=0;
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=nxt[i]){	
//			cout<<x<<" "<<vis[x]<<" GG\n";
			if (i==del || i==(del^1)) continue;
			int y=to[i];
			if (diss[y]>diss[x]+w[i]){
				diss[y]=diss[x]+w[i];
				q.push(make_pair(-diss[y],y));
			}
		}
	}
}
namespace SHIT{
	const int M=2e5+10,E=1e6+10;
	int head[M],nxt[E],to[E],w[E],cnt,fr[E];
	//int X[E],Y[E],W[E];
	int n,m;
	LL dis[M];
	bool vis[M];
	void add(int x,int y,int v){
		nxt[++cnt]=head[x]; head[x]=cnt; to[cnt]=y; w[cnt]=v; fr[cnt]=x;
	}
	void dij(){
		priority_queue<pair<LL,int> > q;
		q.push(make_pair(0,1)); ms(vis,0); ms(dis,1); inf=dis[1]; dis[1]=0;
		while (!q.empty()){
			int x=q.top().second; q.pop();
			if (vis[x]) continue;
			vis[x]=1;
			for (int i=head[x];i;i=nxt[i]){	
//				cout<<x<<" "<<vis[x]<<" GG\n";
				int y=to[i];
				if (dis[y]>dis[x]+w[i]){
					dis[y]=dis[x]+w[i];
					q.push(make_pair(-dis[y],y));
				}
			}	
		}
	}
	vector<pair<int,LL> > vv[M],v[M];
	int num[M];
	bool h[E];
	LL ans[M];
	multiset<int> s;
	void solve(){
		n=read(); m=read(); cnt=1; 
		F(i,1,m){
			int x=read(),y=read(),v=read();
			if (x==y) continue;
			add(x,y,v);
			add(y,x,v);
		}
		dij();
		F(x,2,n){
			for (int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if (dis[y]==dis[x]+w[i]) {
					num[x]++;
					if (y==x-1) h[i]=h[i^1]=1;
				}
			}
			if (num[x]>1) ans[x]=dis[x];
		}
		F(i,1,cnt){
			if (!h[i]){
				v[fr[i]].pb(make_pair(to[i],dis[fr[i]]+dis[to[i]]+w[i]));
				vv[to[i]].pb(make_pair(to[i],dis[fr[i]]+dis[to[i]]+w[i]));
			}
		}
		F(i,0,SZ(v[1])) s.insert(v[1][i].second); 
		F(i,2,n){
			F(j,0,SZ(v[i-1])){
				s.insert(v[i-1][j].second);
			}
			F(j,0,SZ(vv[i-1])){
				s.erase(vv[i-1][j].second);
			}
			if (ans[i]) continue; 
			ans[i]=*s.begin()-dis[i];
		}
		F(i,1,n){
			cout<<ans[i]<<" ";
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num=read();
	if (Num>=12 && Num<=16){
		SHIT::solve();
		return 0;
	}
	n=read(); m=read(); cnt=1;
	F(i,1,m){
		int x=read(),y=read(),v=read();
		if (x==y) continue;
		add(x,y,v);
		add(y,x,v);
//		X[i]=x; Y[i]=y; W[i]=v;
	}
	dij(cnt+10);
//	cout<<dis[n]<<"\n";
	cout<<"0 ";
	F(x,2,n){
		LL mindis=inf; int num=0,fuck=0;
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (dis[x]==dis[y]+w[i]){
				num++;
				fuck=i;
			}
		}
		if (num>1){
			cout<<dis[x]<<" ";
			continue;
		}
//		cout<<fuck<<" "<<num<<" GGGGGHHHH\n";
		dijj(fuck);
		cout<<(diss[x]==inf ? -1 : diss[x])<<" ";
	}
	return 0;
}



