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
void write(ll x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
void print(ll x){
	write(x); putchar(' ');
}
void writeln(ll x){
	write(x); puts("");
}
ll a,n,m,cha;
ll pow2[110];
vector <ll> p;
int main(){
	fre("review")
	read(a);
	for (ll i=1;i/2<=a;i*=2){
		pow2[n++]=i;
	}
	n-=2;
	m=(n+1)*(n+2)/2;
	if (pow2[n]==a){
		print(n+2);
		writeln(m);
		for (ll i=1;i<=n+2;i++){
			for (ll j=i+1;j<=n+2;j++){
				print(i); writeln(j);
			}
		}
		return 0;
	}
	n++;
	m=(n+1)*(n+2)/2;
	print(n+2);
	cha=pow2[n]-a;
	for (ll i=n;i>=0;i--){
		if (cha>=pow2[i]){
			cha-=pow2[i];
			p.push_back(i+1);
		}
	}
	ll k=p.size();
	writeln(m-k);
	k--;
	for (ll i=n+2;i>=2;i--){
		if (i+p[k]==n+2) k--;
		else print(1),writeln(i);
	}
	for (ll i=2;i<=n+2;i++){
		for (ll j=i+1;j<=n+2;j++){
			print(i); writeln(j);
		}
	}
	return 0;
}
