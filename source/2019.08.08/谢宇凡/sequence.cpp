#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int m,n;
long long a[500010],b[500010];

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=m;++i){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		int de=(s+e)/(r-l+1);
		a[l]+=s;
		a[l+1]+=de-s;
		a[r+1]-=e;
	}
	long long ans=a[1];
	b[1]=a[1];
	for (int i=2;i<=n;++i){
		b[i]=a[i]+2*b[i-1]-b[i-2];
		ans^=b[i];
	}
	printf("%lld",ans);
	return 0;
}


