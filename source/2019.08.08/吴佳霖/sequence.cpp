#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+5;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int ans;
int a[maxn];
int n,m;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i;
	read(n);read(m);
	for(i=1;i<=m;++i){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		int k=(e-s)/(r-l);
		for(int j=l;j<=r;++j){
			a[j]+=s+k*(j-l);
		}
	}
	ans=a[1];
	for(i=2;i<=n;++i)ans=ans^a[i];
	printf("%d",ans);
	return 0;
}
