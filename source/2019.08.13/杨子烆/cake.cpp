#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
long long qg[301][301];
bool vis[301][301];
long long ans;
long long dfs(int n,int m){
	long long res=0;
	if(n==1&&m==1){
		res=1;
		return res;
	}
	if(vis[n][m]){
		res=qg[n][m];
		return res;
	}
	for(int i=1;i<n;i++){
		res=(res+((dfs(i,m))%Mod*(dfs(n-i,m))%Mod)%Mod)%Mod;
	}
	for(int i=1;i<m;i++){
		res=(res+((dfs(n,i))%Mod*(dfs(n,m-i))%Mod)%Mod)%Mod;
	}	
	vis[n][m]=true;
	qg[n][m]=res;
	return res;
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
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	read(n);read(m);
	cout<<dfs(n,m);
	return 0;
}


