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
priority_queue <ll> a,b,c;
ll ans,s,n;
int main(){
	fre("debate")
	read(n);
	for (int i=1;i<=n;i++){
		ll opt,x;
		read(opt); read(x);
		if (opt==11) ans+=x,s++;
		if (opt==10) a.push(x);
		if (opt==1) b.push(x);
		if (opt==0) c.push(x);
	}
	while (!a.empty()&&!b.empty()){
		ll sa=a.top(); ll sb=b.top();
		ans+=sa+sb;
		a.pop(); b.pop();
	}
	while (s--){
		ll sa=-1,sb=-1,sc=-1;
		if (!a.empty()) sa=a.top();
		if (!b.empty()) sb=b.top();
		if (!c.empty()) sc=c.top();
		if (sa>sb&&sa>sc){
			ans+=sa; a.pop();
		}
		if (sb>sa&&sb>sc){
			ans+=sb; b.pop();
		}
		if (sc>sb&&sc>sa){
			ans+=sc; c.pop();
		}
	}
	writeln(ans);
	return 0;
}

