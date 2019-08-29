#include<bits/stdc++.h>
#define N 300
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,m;
struct node{
	int L,R;
};
node a[N];
ll ans;
int k[5];
int sum[N];
int b[N];
int r[N];
bool cmp(node x,node y){
	return x.L<y.L;
}
ll count(int x){
	ll t=x,w=x,res=0;
	for (int i=0;i<5;i++){
		res=res+t*k[i];
		t*=w;
	}
	return res;
}
bool checktask1(){
	for (int i=1;i<=n;i++) if (a[i].L!=1||a[i].R!=m) return false;
	return true;
}
void subtask1(){
	printf("%lld\n",count(n));
	return;
}
bool check(){
	int j=1;
	int lef=1,rig=0;
	for (int i=1;i<=m;i++){
		if (lef<=rig){
			nth_element(r+lef,r+lef,r+rig+1);
			if (r[lef]<i) return false;
		}
		while (j<=n&&a[j].L<=i){
			r[++rig]=a[j].R;
			++j;
		}
		if (rig-lef+1<b[i]) return false;
		nth_element(r+lef,r+b[i]+lef-1,r+rig+1);
		lef+=b[i];
	}
	return true;
}
void dfs(int dep,int num){
	if (dep>m){
		if (num==n){
			ll res=0;
			if (check()) for (int i=1;i<=m;i++) res+=count(b[i]);
			ans=max(ans,res);
		}
		return;
	}
	for (int i=0;i<=n-num&&i<=sum[dep];i++){
		b[dep]=i;
		dfs(dep+1,num+i);
	}
	return;
}
void subtask2(){
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		sum[a[i].L]++;
		sum[a[i].R+1]--;
	}
	for (int i=1;i<=m;i++) sum[i]+=sum[i-1];
	dfs(1,0);
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for (int i=0;i<5;i++) read(k[i]);
	for (int i=1;i<=n;i++){
		read(a[i].L);
		read(a[i].R);
	}
	if (checktask1()){
		subtask1();
		return 0;
	}
	subtask2();
	return 0;
}

