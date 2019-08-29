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
ll xs[6];
ll g(ll x){
	ll s=x,ans=0;
	for (int i=1;i<=5;i++){
		ans+=s*xs[i]; s*=x;
	}
	return ans;
}
struct node{
	int l,r;
}a[310];
bool cmp1(node x,node y){
	if (x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int n,m;
int main(){
	fre("stand")
	read(n); read(m);
	for (int i=1;i<=5;i++) read(xs[i]);
	for (int i=1;i<=n;i++){
		read(a[i].l); read(a[i].r);
	}
	sort(a+1,a+n+1,cmp1);
//	for (int i=1;i<=n;i++){
//		cout<<a[i].l<<" "<<a[i].r<<endl;
//	}
	ll ans=0,s=1;
	int w=a[1].r;
	for (int i=2;i<=n;i++){
//		cout<<w<<endl;
		if (w<a[i].l||w>a[i].r){
//			cout<<s<<endl;
			w=a[i].r;
			ans+=g(s); s=0;
		}
		s++;
	}
//	cout<<s<<endl;
//	cout<<w<<endl; 
	ans+=g(s); 
	reverse(a+1,a+n+1);
	ll ans1=0; s=1;
	w=a[1].l;
	for (int i=2;i<=n;i++){
//		cout<<w<<endl;
		if (w<a[i].l||w>a[i].r){
//			cout<<s<<endl;
			w=a[i].l;
			ans1+=g(s); s=0;
		}
		s++;
	}
//	cout<<s<<endl;
//	cout<<w<<endl; 
	ans1+=g(s);
	writeln(max(ans,ans1));
	return 0;
}

