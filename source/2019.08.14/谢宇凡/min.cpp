#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> void read(T &x){
	x=0;char ch=getchar();T f=0;
	for (;!isdigit(ch);ch=getchar())	f|=ch=='-';
	for (;isdigit(ch);ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	x=f?-x:x;
}

ll h[200010],f[200010],maxn[200010];
int ma[200010],a[200010];
int n,A,B,C,D;

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(A);read(B);read(C);read(D);
	for (int i=1;i<=n;++i){
		ll a[i];
		read(a[i]);
		f[i]=A*a[i]*a[i]*a[i]+B*a[i]*a[i]+C*a[i]+D;
		if (f[i]>maxn[i-1]&&a[ma[i-1]]<=a[i])	ma[i]=i,maxn[i]=f[i];
		else 	ma[i]=ma[i-1],maxn[i]=maxn[i-1];
	}
	for (int i=1;i<=n;++i)
		h[i]=max(h[ma[i]],f[i]+h[i-1]);
	printf("%lld\n",h[n]);
	return 0;
}

