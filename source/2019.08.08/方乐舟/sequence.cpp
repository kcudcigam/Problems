#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,s,e,ss;
long long a[500010],b[500010];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=m;i++){
		read(l);read(r);read(s);read(e);
		a[l]+=s;a[r+1]-=e;b[l+1]+=(e-s)/(r-l);b[r+1]-=(e-s)/(r-l);
	}
	for (int i=2;i<=n;i++){
		a[i]+=b[i]+a[i-1];
		b[i+1]+=b[i];
	}
	ss=a[1];
	for (int i=2;i<=n;i++){
		 ss=ss^a[i];
	}
	printf("%lld\n",ss);
	return 0;
}


