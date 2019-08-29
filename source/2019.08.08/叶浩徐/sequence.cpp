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
#define int long long
struct seg{
	ll val,l,r,add;
}t[2000010];
int n,m;
void solve1(){
	for (int i=1;i<=m;i++){
		ll l,r,s,e,d,k;
		read(l); read(r); read(s); read(e);
		k=d=(e-s)/(r-l);
		for (int j=l;j<=r;j++) t[j].val+=k,k+=d;
		if (s==e) for (int j=l;j<=r;j++) t[j].val+=s;
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans^=t[i].val;
	writeln(ans);
	exit(0);
}
void build(int p,int l,int r){
	t[p].l=l; t[p].r=r;
	if (l==r) return;
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}
void spread(int p){
	if (t[p].add){
		t[p*2].val+=t[p].add;
		t[p*2+1].val+=t[p].add;
		t[p*2].add+=t[p].add;
		t[p*2+1].add+=t[p].add;
		t[p].add=0;
	}
}
void change(int p,int l,int r,int d){
	if (l<=t[p].l&&r>=t[p].r){
		t[p].val+=d;
		t[p].add+=d;
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if (l<=mid) change(p*2,l,r,d);
	if (r>mid) change(p*2+1,l,r,d);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
int query(int p,int l,int r){
	if (l<=t[p].l&&r>=t[p].r) return t[p].val;
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	int s=0;
	if (l<=mid) s+=query(p*2,l,r);
	if (r>mid) s+=query(p*2+1,l,r);
	return s;
}
signed main(){
	fre("sequence")
	read(n); read(m);
	if (n<=1000) solve1();
	build(1,1,n);
	for (int i=1;i<=m;i++){
		ll l,r,s,e,d;
		read(l); read(r); read(s); read(e);
		d=(e-s)/(r-l);
		change(1,l,r,d);
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans^=query(1,i,i);
	writeln(ans);
	return 0;
}

