#include <bits/stdc++.h>
#define rg register
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int MAXN=5e5+10;
typedef unsigned long long ull;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
struct Seg{int l,r;ull tag;}tr[MAXN<<2];
inline void pushdown(int x){tr[lc].tag+=tr[x].tag,tr[rc].tag+=tr[x].tag,tr[x].tag=0;}
inline void build(int x,int l,int r){
	tr[x].l=l,tr[x].r=r,tr[x].tag=0;
	if(l==r) return;
	build(lc,l,mid),build(rc,mid+1,r);
}
inline void Change(int x,int ql,int qr,ull s){
	int l=tr[x].l,r=tr[x].r;
	if(ql<=l&&r<=qr){tr[x].tag+=s;return;}
	if(ql<=mid)Change(lc,ql,mid,s);
	if(qr>mid)Change(rc,mid+1,qr,s);
}
inline ull query(int x,int p){
	int l=tr[x].l,r=tr[x].r;
	if(l==r)return tr[x].tag;
	pushdown(x);
	if(p<=mid)return query(lc,p);
	else return query(rc,p);
}
int n,m;
ull l[MAXN],r[MAXN],s[MAXN],e,d[MAXN],a[MAXN],ans;
bool flag=1;
int main(){
	freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	read(n),read(m);build(1,1,n);
	for(rg int i=1;i<=m;i++){read(l[i]),read(r[i]),read(s[i]),read(e);d[i]=(e-s[i])/(r[i]-l[i]);if(s[i]!=e)flag=0;}
	if(flag==1){
		for(rg int i=1;i<=m;i++)Change(1,l[i],r[i],s[i]);
		for(rg int i=1;i<=n;i++)ans^=query(1,i);
	}
	else{
		for(rg int i=1;i<=m;i++)
			for(rg int j=l[i];j<=r[i];j++)a[j]+=(j-l[i])*d[i]+s[i];
		for(rg int i=1;i<=n;i++) ans^=a[i];
	}
	printf("%lld",ans);
	return 0;
}
