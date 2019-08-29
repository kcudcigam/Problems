#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int a[1111],b[1111],c[1111];
int ans=0;
int n,X;
void tryit(int kk,int sum){
	if (kk>n){
		if (sum==X){
			ans++;
		}
		return;
	}
	else {
		for (int i=0;i<=b[kk];i++){
			for (int j=0;j<=i&&j<=c[kk];j++){
				tryit(kk+1,sum+(i-j)*a[kk]);
			}
		}
	}
}
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
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);
	read(X);
	for (int i=1;i<=n;i++){
		read(a[i]);
		read(b[i]);
		read(c[i]);
	}
	if (n>8){
		writeln(n*X%MOD);
		return 0;
	}
	tryit(1,0);
	writeln(ans%MOD);
	return 0;
}

