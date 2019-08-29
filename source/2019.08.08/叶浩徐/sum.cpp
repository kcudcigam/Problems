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
ll n,b[100010],a[100010],f1,f2,ans1,ans2,k,m;
int main(){
	fre("sum")
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++){
		ll s=0;
		while (a[i]>=0&&i<=n) s+=a[i],i++;
		b[++m]=s; b[++m]=a[i];
	}
	if (b[m]==0) m--;
	int ct=0,cnt=0;
	for (int i=1;i<=m;i++){
		if (b[i]>0) ct++;
		if (b[i]==0) cnt++;
	}
	if (ct==2){
		ll s=0;
		for (int i=1;i<=m;i++){
			if (b[i]>0) s+=b[i];
		}
		writeln(s);
		return 0;
	}
	if (ct==1&&cnt==1){
		for (int i=1;i<=m;i++){
			if (b[m]>0){
				writeln(b[m]);
				return 0;
			}
		}
	}
	for (int i=1;i<=m;i++){
		f1+=b[i];
		if (f1>ans1){
			k=i; ans1=f1;
		}
		if (f1<0) f1=0;
	}
	for (int i=m;i>k;i--){
		f2+=b[i];
		ans2=max(ans2,f2);
		if (f2<0) f2=0;
	}
	writeln(ans1+ans2);
	return 0;
}

