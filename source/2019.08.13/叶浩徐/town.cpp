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
int son[300010],f[300010],s[300010],n;
int getf(int x){
	if (f[x]==x) return x;
	s[x]=max(s[x],s[f[x]]);
	return f[x]=getf(f[x]);
}
void merge(int x,int y){
	int a=getf(x),b=getf(y);
	f[a]=b;
	s[a]+=max(son[a],son[b]);
	son[b]+=son[a];
	writeln(s[a]);
	return;
}
int main(){
	fre("town")
	read(n);
	for (int i=1;i<=n;i++){
		f[i]=i; son[i]=1; s[i]=0;
	}
	for (int x,y,i=1;i<n;i++){
		read(x); read(y);
		if (x>y) swap(x,y);
		merge(x,y);
	}
	return 0;
}

