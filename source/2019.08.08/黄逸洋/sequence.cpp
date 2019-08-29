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
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
long long a[500010],n,m,b[500010];
long long l[500010];
long long r[500010];
long long s[500010];
long long e[500010];
long long flg=1;
void doit1(){
	for(long long i=1;i<=m;i++){
		b[l[i]]+=s[i];
		b[r[i]+1]-=s[i];
	}
	for(long long i=1;i<=n;i++){
		b[i]+=b[i-1];
	}
	for(long long i=1;i<=n;i++){
		a[i]+=b[i];
	}
}
void doit2(){
	for(long long i=1;i<=m;i++){
		long long gc=(l[i]==r[i]?s[i]:(e[i]-s[i])/(r[i]-l[i]));
			
		for(long long j=l[i];j<=r[i];j++){
			a[j]+=s[i]+gc*(j-l[i]);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);

	read(n);read(m);
	for(long long i=1;i<=m;i++){
		read(l[i]);read(r[i]);read(s[i]);read(e[i]);
		if(s[i]!=e[i])flg=0;
		
	}
	
	if(flg)doit1();
	else doit2();
	
	long long ans=0;
	for(long long i=1;i<=n;i++)ans^=a[i];
	writeln(ans);
	return 0;
}
/*
5 2
1 5 2 10
2 4 1 1

*/

