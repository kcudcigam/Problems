#include<bits/stdc++.h>
using namespace std;
int fa[300001];
int dis[300001];
vector<int>lt [300001];
bool vis[300001];
int get(int x){
	if(fa[x]==x)return x;
	else return fa[x]=get(fa[x]);
}
long long ste=0;
int z;
void dfs(int f,int y){
	if(y>ste){
		ste=y;z=f;
}
	vis[f]=true;
	for(int i=0;i<lt[f].size();i++){
		if(!vis[lt[f][i]]){
			dfs(lt[f][i],y+1);
			vis[lt[f][i]]=false;
		}
	}
	vis[f]=false;
}
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;
	int x,y,fx,fy;
	read(n);
	for(int i=1;i<=n;i++)fa[i]=i;

	for(int i=1;i<=n-1;i++){
		read(x);read(y);
		lt[x].push_back(y);
		lt[y].push_back(x);
		dfs(x,0);
		ste=0;
		dfs(z,0);
		cout<<ste<<endl;
		ste=0;
	}

	return 0;
}


