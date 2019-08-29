#include<bits/stdc++.h>
using namespace std;
bool dgt[10];
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	read(t);
	while (t--){
		int n;
		read(n);
		int cnt=0;
		memset(dgt,true,sizeof(dgt));
		while (n){
			int ld=n%10;
			if (dgt[ld]){
				dgt[ld]=false;
				cnt++;
			}
			n/=10;
		}
		int ans=ceil(cnt*1.0/2);
		writeln(ans);
	}
	return 0;
}

