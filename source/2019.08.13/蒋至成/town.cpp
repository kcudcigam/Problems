#include<bits/stdc++.h>
using namespace std;
const int inf=1061109567;
int n;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int f[301],maxn[301],spf[301];
vector<int> a[301];
vector<int> d[301];
bool h[301];
int fat(int nowx){
	if(f[nowx]==nowx)return nowx;
	return f[nowx]=fat(f[nowx]);
}
void spfa(int s){
	memset(spf,0x3f,sizeof(spf));
	memset(h,0,sizeof(h));
	queue<int> q;
	q.push(s);
	h[s]=1;
	spf[s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		h[t]=0;
		for(int i=0;i<a[t].size();++i){
			if(spf[t]+1<spf[a[t][i]]){
				
				spf[a[t][i]]=spf[t]+1;
				if(!h[a[t][i]]){
					q.push(a[t][i]);
					h[a[t][i]]=1;
				}
			}
		}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout); 
	read(n);
	for(int i=1;i<=n;++i){
		f[i]=i;
		d[i].push_back(i);
	}
	for(int i=1;i<n;++i){
		int x,y;
		read(x);read(y);
		int u=fat(x),v=fat(y);
		a[x].push_back(y);
		a[y].push_back(x);
		f[u]=v;
		maxn[v]=max(maxn[u],maxn[v]);
		for(int j=0;j<d[u].size();++j)d[v].push_back(d[u][j]);
		d[u].clear();
		for(int i=0;i<d[v].size();++i){
			spfa(d[v][i]);
			for(int j=0;j<d[v].size();++j)if(spf[d[v][j]]!=inf)maxn[v]=max(maxn[v],spf[d[v][j]]);
		}
		cout<<maxn[v]<<'\n';
	}
	return 0;
}


