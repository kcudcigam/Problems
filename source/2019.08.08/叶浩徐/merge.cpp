#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x);
	puts("");
}
int ans[500010],f[500010],n,m,opt,a,b;
int getf(int x){
	if (f[x]==x) return x;
	return f[x]=getf(f[x]);
}
int main(){
	fre("merge")
	read(n); read(m);
	for (int i=1;i<=n;i++) f[i]=i;
	while (m--){
		read(opt); read(a); read(b);
		if (opt==1){
			int x=getf(a);
			int y=getf(b);
			if (x!=y) f[x]=y;
		}
		if (opt==2){
			for (int i=1;i<=n;i++){
				if (f[i]==f[a]) ans[i]+=b;
			}
		}
	}
	for (int i=1;i<n;i++) write(ans[i]),putchar(' ');
	writeln(ans[n]);
	return 0;
}

