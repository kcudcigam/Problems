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
long long f[2000][2000];
long long F(long long x,long long y){
	f[1][1]=f[1][2]=f[2][1]=1;
	for(long long i=1;i<=x;i++){
		for(long long j=1;j<=y;j++){
			if(f[i][j])continue;
			for(long long k=1;k<i;k++)f[i][j]=(f[i][j]+f[k][j]*f[i-k][j]%p)%p;
			for(long long k=1;k<j;k++)f[i][j]=(f[i][j]+f[i][k]*f[i][j-k]%p)%p;
		}
	}
	return f[x][y];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);

	long long n,m;
	read(n);read(m);
	writeln(F(n,m));
	return 0;
}



