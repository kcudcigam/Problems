#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
long long p=1e9+7;
long long n,X;
long long a[2000],b[2000],c[2000];
long long t[2000],ans=0;
long long cnt=0;
void dfs2(long long dep,long long tot,long long dest){
	if(tot>dest)return;
	if(dep>n)return;
	if(tot==dest){
		cnt=(cnt+1)%p;
		return;
	}
	for(long long i=0;i<=c[dep];i++){
		dfs2(dep+1,tot+a[dep]*i,dest);
	}
}
bool check(long long tot){
	if(tot<X)return 0;
	long long sy=tot-X;
	for(long long i=1;i<=n;i++){
		if(a[i]<=sy&&t[i])return 0;
	}
	return 1;
}
void dfs(long long dep,long long tot){
	if(dep>n){
		if(check(tot)){
			cnt=0;
			dfs2(1,0,tot-X);
			ans=(ans+cnt%p)%p;
//			for(long long i=1;i<=n;i++)cout<<t[i];
//			cout<<' '<<tot<<' '<<X<<' '<<cnt<<endl;
		}
	}else{
		for(long long i=0;i<=b[dep];i++){
			t[dep]=i;
			dfs(dep+1,tot+a[dep]*i);
		}
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);

	read(n);read(X);
	for(long long i=1;i<=n;i++){
		read(a[i]);read(b[i]);read(c[i]);
	}
	
	dfs(1,0);
	writeln(ans);
	return 0;
}
/*
3 10
1 5 3
3 2 2
5 3 2

3 10
1 5 0
3 2 2
5 3 2

*/


