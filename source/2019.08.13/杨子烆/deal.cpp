#include<bits/stdc++.h>
long long mo=1000000007;
using namespace std;
int xm[1001][2];
int dy[1001][2];
long long xmnum[20001];
long long dynum[20001];
int n,xx;
long long dfs(int maxx,int x,int n){
	int i=1;long long ans=0;
	if(x==0)return 1;
	while(xm[i][0]<=x&&i<=n){
		if(xm[i][1]>0&&maxx-xm[i][0]<xx){
			xm[i][1]--;
			ans+=dfs(maxx,x-xm[i][0],i);
			ans%=mo;
			xm[i][1]++;
		}
		i++;
	}
	return ans;
}
long long dfs1(int maxx,int x,int n){
	int i=1;long long ans=0;
	if(x==0)return 1;
	while(dy[i][0]<=x&&i<=n){
		if(dy[i][1]>0&&maxx-dy[i][0]<xx){
			dy[i][1]--;
			ans+=dfs1(maxx,x-dy[i][0],i);
			ans%=mo;
			dy[i][1]++;
		}
		i++;
	}
	return ans;
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

	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	long long res=0;
	read(n);read(xx);
	if(xx==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		read(xm[i][0]);read(xm[i][1]);read(dy[i][1]);
		dy[i][0]=xm[i][0];
	}
	for(int i=1;i<=20000;i++){
		xmnum[i]=dfs(i,i,n)%mo;
		dynum[i]=dfs1(i,i,n)%mo;
	}
	dynum[0]=1;
	for(int i=xx;i<=20000;i++){
		res=(res+(xmnum[i]*dynum[i-xx])%mo)%mo;
	}
	cout<<res;
	return 0;
}


