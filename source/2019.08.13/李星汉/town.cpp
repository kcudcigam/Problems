#include<bits/stdc++.h>

using namespace std;

#define N 300000

int d1[N+5],d2[N+5],dep[N+5],head[N+5],vis[N+5],fa[N+5],A[N+5],B[N+5];
int n,i,j,cnt;

int p1[N+5],p2[N+5]; // case 3

struct edge{
	int des,next,id;
}e[2*N+5];

void addedge(int a,int b,int id){
	cnt++;
	e[cnt].id = id;
	e[cnt].des = b;
	e[cnt].next = head[a];
	head[a] = cnt;
}

inline int read(){
	int s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

inline void write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x / 10);
	putchar('0' + x % 10);
}

void ud(int u,int x){
	if(x > d1[u]){d2[u] = d1[u];d1[u] = x;return;}
	if(x > d2[u]){d2[u] = x;return;}
}

void ud2(int u,int dir,int x){ // case 3
	if(dir == p1[u]){d1[u] = max(d1[u],x);return;}
	if(dir == p2[u]){
		d2[u] = max(d2[u],x);
		if(d2[u] > d1[u])swap(d1[u],d2[u]),swap(p1[u],p2[u]);
		return;
	}
	if(x > d1[u]){d2[u] = d1[u];p2[u] = p1[u];d1[u] = x;p1[u] = dir;return;}
	if(x > d2[u]){d2[u] = x;p2[u] = dir;return;}
}

void dfs(int u,int f,int x){
	int i,v;
	vis[u] = x;
	d1[u] = d2[u] = 0;
	for(i = head[u];i;i = e[i].next){
		v = e[i].des;
		if(v == f)continue;
		dfs(v,u,x);
		if(e[i].id <= x)ud(u,d1[v] + 1);
	}
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n = read();
	int i,j,a,b;
	bool bo = 1;
	for(i = 1;i < n;i++){
		A[i] = read();B[i] = read();
		if(!(A[i] <= i && B[i] == i + 1))bo = 0;
	}
	if(bo){
//cout<<"bo!!!"<<endl;
		int ans = 0;
		for(i = 1;i < n;i++){
			a = A[i];b = B[i];
			fa[b] = a;
			for(int u = b,cur = 1;fa[u];u = fa[u],cur++){
				ud2(fa[u],u,cur);
//cout<<fa[u]<<" "<<d1[fa[u]]<<" "<<d2[fa[u]]<<" "<<p1[fa[u]]<<" "<<p2[fa[u]]<<endl;
				ans = max(ans,d1[fa[u]] + d2[fa[u]]);
			}
			write(ans);
			putchar('\n');
		}
		return 0;
	}
	for(i = 1;i < n;i++){
		a = A[i];b = B[i];
		addedge(a,b,i);
		addedge(b,a,i);
		dfs(a,0,i);
//for(j = 1;j <= n;j++)cout<<"j="<<j<<" d1="<<d1[j]<<" d2="<<d2[j]<<endl;
		int ans = 0;
		for(j = 1;j <= n;j++)if(vis[j] == i)ans = max(ans,d1[j] + d2[j]);
		write(ans);
		putchar('\n');
	}
	return 0;
}

