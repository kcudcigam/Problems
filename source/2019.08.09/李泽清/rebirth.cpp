#include<bits/stdc++.h>
#define LL long long
#define pa pair<LL,int>
#define mp make_pair
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const LL Inf=1000000000000000000;
const int N=1000010;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,m;
int to[N],ne[N],st[N],sl=1,w[N],pre[N],preu[N],prew[N];
LL dis[N],d2[N],tag[N];
int del[N];
priority_queue<pa,vector<pa>,greater<pa> > d,dd;
vector<pa> v[200010];
set<int> s[200010];
set<pa> ss[200010];
void Ads(int x,int y,int val){to[++sl]=y;ne[sl]=st[x];st[x]=sl;w[sl]=val;}
void Dij(){
	F(i,2,n)dis[i]=d2[i]=Inf;
	d.push(mp(0,1));
	while(!d.empty()){
		while((!dd.empty())&&dd.top()==d.top())d.pop(),dd.pop();
		if(d.empty())break;
		int u=d.top().second;d.pop();
		for(int i=st[u];i;i=ne[i])
			if(dis[to[i]]>dis[u]+w[i]){
				dd.push(mp(dis[to[i]],to[i]));
				dis[to[i]]=dis[u]+w[i];
				d.push(mp(dis[to[i]],to[i]));
				pre[to[i]]=i;
				preu[to[i]]=u;
				prew[to[i]]=w[i];
			}
	}
}
void dfs(int u){
	for(auto to:v[u]){
		dfs(to.second);
		if(ss[u].size()<ss[to.second].size()){
			swap(ss[u],ss[to.second]);
			swap(tag[u],tag[to.second]);
			tag[u]+=to.first;
			tag[to.second]-=to.first;
		}
		for(auto ii:ss[to.second])
			ss[u].insert(mp(ii.first+tag[to.second]-tag[u]+to.first,ii.second));
		if(s[u].size()<s[to.second].size())swap(s[u],s[to.second]);
		for(auto ii:s[to.second])s[u].insert(ii);
		s[to.second].clear();ss[to.second].clear();
	}
	//printf("Solve %d\n",u);
	s[u].insert(u);
	for(int i=st[u];i;i=ne[i])
		if((!s[u].count(to[i]))&&del[i]==0){
			ss[u].insert(mp(dis[to[i]]+w[i]-tag[u],to[i]));
			//printf("Add %lld %d\n",dis[to[i]]+w[i],to[i]);
		}
	while(!ss[u].empty()){
		auto ii=*ss[u].begin();
		if(s[u].count(ii.second))ss[u].erase(ss[u].begin());
		else break;
	}
	//printf("tag:%lld\n",tag[u]);
	//for(auto ii:ss[u])printf("%lld %d\n",ii.first,ii.second);
	//printf("\n");
	if(ss[u].empty())d2[u]=-1;
	else d2[u]=(*ss[u].begin()).first+tag[u];
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	R();
	n=R();m=R();
	F(i,1,m){
		int x=R(),y=R(),val=R();
		if(x==y)continue;
		Ads(x,y,val);Ads(y,x,val);
	}
	Dij();
	F(i,2,n){
		del[pre[i]]=1;
		del[pre[i]^1]=1;
	}
	F(i,2,n)v[preu[i]].push_back(mp(prew[i],i));
	dfs(1);
	d2[1]=0;
	F(i,1,n)if(d2[i]==Inf)d2[i]=-1;
	F(i,1,n)cout<<d2[i]<<' ';
	cout<<'\n';
	return 0;
}
