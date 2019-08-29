#include<bits/stdc++.h>
using namespace std;
long long f[311][311];
const long long MOD=1000000007;
template <typename T> void read(T &x){
	T f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	f[1][1]=1;
	for (int i=2;i<=m;i++){
		long long sum=0;
		for (int j=1;j<i;j++){
			sum+=f[1][j]*f[1][i-j];
			sum%=MOD;
		}
		f[1][i]=sum;
	}
	for (int i=2;i<=n;i++){
		long long sum=0;
		for (int j=1;j<i;j++){
			sum+=f[j][1]*f[i-j][1];
			sum%=MOD;
		}
		f[i][1]=sum;
	}
	for (int i=2;i<=n;i++){
		for (int j=2;j<=m;j++){
			long long sum=0;
			for (int k=1;k<i;k++){
				sum+=f[k][j]*f[i-k][j];
				sum%=MOD;
			}
			for (int k=1;k<j;k++){
				sum+=f[i][k]*f[i][j-k];
				sum%=MOD;
			}
			f[i][j]=sum;
		}
	}
	writeln(f[n][m]);
	return 0;
}

