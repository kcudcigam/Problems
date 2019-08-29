#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
#define int long long
bool vis[100010];
int dis[100010];
struct edge{
	int to,len;
};
vector <edge> e[100010];
#define mp make_pair
#define pii pair<int,int>
priority_queue < pii > q;
int n,m;
int dijkstra(int s,int a){
	for (int i=1;i<=n;i++){
		dis[i]=INT_MAX; vis[i]=0;
	}
	q.push(mp(0,s)); dis[s]=0;
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=0;i<e[x].size();i++){
			int y=e[x][i].to;
			if ((x==s&&y==a)||(x==a&&y==s)) continue;
			if (e[x][i].len+dis[x]<dis[y]){
				dis[y]=e[x][i].len+dis[x];
				if (!vis[y]){
					q.push(mp(-dis[y],y));
				}
			}
		}
	}
	return dis[1];
}
int num;
void write(int x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
void print(int x){
	write(x); putchar(' ');
}
void writeln(int x){
	write(x); puts("");
}
signed main(){
	fre("rebirth")
	read(num);
	read(n); read(m);
	for (int x,y,w,i=1;i<=m;i++){
		read(x); read(y); read(w);
		e[x].push_back(edge{y,w});
		e[y].push_back(edge{x,w});
	}
	print(0);
	for (int i=2;i<n;i++){
		int ans=-1;
		for (int j=0;j<e[i].size();j++){
			int s=dijkstra(i,e[i][j].to);
			ans=max(ans,s);
		}
		if (ans==INT_MAX) print(-1);
		else print(ans);
	}
	int ans=-1;
	for (int j=0;j<e[n].size();j++){
		ans=max(ans,dijkstra(n,e[n][j].to));
	}
	if (ans==INT_MAX) writeln(-1);
	else writeln(ans);
	return 0;
}

