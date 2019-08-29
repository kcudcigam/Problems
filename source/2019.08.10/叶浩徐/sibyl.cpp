#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
template <typename T> inline void print(T x){
	write(x); putchar(' ');
}
const int N=300010;
int tag[N],n,m,q,opt,x,y;
vector <int> e[N];
int main(){
	fre("sibyl")
	read(n); read(m); read(q);
	for (int i=1;i<=m;++i){
		read(x); read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	while (q--){
		read(opt);
		if (opt){
			read(x); read(y);
			tag[x]+=y;
		}else{
			read(x);
			int ans=tag[x];
			for (size_t i=0;i<e[x].size();++i){
				ans+=tag[e[x][i]];
			}
			writeln(ans);
		}
	}
	return 0;
}
