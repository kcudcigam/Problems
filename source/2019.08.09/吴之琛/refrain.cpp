#include<bits/stdc++.h>
#define N 110
#define ll long long
#define Mod 1000000007
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int len1[N],len2[N];
int a[N],vis[N],c1[N][N],c2[N][N],g1[N][N],g2[N][N];
int Num,n,m1,m2;
ll ans,tot;
ll jc(int x){
	ll res=1;
	for (int i=1;i<=x;i++) res=(res*i)%Mod;
	return res;
}
ll poww(int x){
	ll res=1,t=2;
	while (x){
		if (x&1) res=(res*t)%Mod;
		t=(t*t)%Mod;
		x>>=1;
	}
	return res;
}
bool check(int p,int q){
	for (int i=1;i<=len1[q];i++) if (!g1[a[c1[q][i]]][p]&&!g1[p][a[c1[q][i]]]) return false;
	for (int i=1;i<=len2[q];i++) if (!g2[a[c2[q][i]]][p]&&!g2[p][a[c2[q][i]]]) return false;
	return true;
}
void dfs(int dep){
	if (dep>n){
		ans++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]&&check(i,dep)){
			a[dep]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	return;
}
void bl(){
	for (int i=1;i<=n;i++) vis[i]=0;
	dfs(1);
	tot=jc(n);
	tot-=ans;
	if (tot<0) tot+=Mod;
	printf("%lld\n",tot);
	return;
}
void subtask1(){
	int m3=n-2*(m1+m2);
	ans=(((jc(m1)*jc(m2))%Mod)*jc(m3))%Mod;
	ans=(((ans*poww(m1))%Mod)*poww(m2))%Mod;
	tot=jc(n);
	tot-=ans;
	if (tot<0) tot+=Mod;
	printf("%lld\n",tot);
	return;
}
void subtask2(){
	tot=jc(n);
	tot-=n;
	if (tot<0) tot+=Mod;
	printf("%lld\n",tot);
	return;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(Num);
	read(n);
	read(m1);
	read(m2);
	for (int i=1;i<=m1;i++){
		int u,v;
		read(u);
		read(v);
		if (u<v) swap(u,v);
		c1[u][++len1[u]]=v;
		g1[u][v]=g1[v][u]=1;
	}
	for (int i=1;i<=m2;i++){
		int u,v;
		read(u);
		read(v);
		if (u<v) swap(u,v);
		c2[u][++len2[u]]=v;
		g2[u][v]=g2[v][u]=1;
	}
	if (Num<=6){
		bl();
		return 0;
	}
	if (Num<=10){
		subtask1();
		return 0;
	}
	if (Num<=14){
		subtask2();
		return 0;
	}
	return 0;
}

