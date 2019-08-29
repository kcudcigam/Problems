#include<bits/stdc++.h>
long long mo=1000000007;
using namespace std;
long long x[200001];
long long f[10001];
long long ans;
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

	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	long long n,a,b,c,d;
	read(n);read(a);read(b);read(c);read(d);
	for(int i=1;i<=n;i++){
		read(x[i]);
	}
	if(a==0&&b==0&&c<=0){
	sort(x+1,x+n+1);
	ans+=x[1]*c+d;
	for(int i=2;i<=n;i++){
		if(x[i]*c+d<0)break;
		else ans+=x[i]*c+d;
	}
	cout<<ans;
}
	else{

		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)f[i]=max(f[i],f[j]);
			
			f[i]+=x[i]*x[i]*x[i]*a;
			f[i]+=x[i]*x[i]*b;
			f[i]+=x[i]*c;
			f[i]+=d;
		}
		long long maxx=-2e18;
		maxx-=19;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,f[i]);
		}
		cout<<maxx;
	}
	return 0;
}


