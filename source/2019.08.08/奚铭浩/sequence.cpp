#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long a[500010];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	read(n);read(m);
	for(int i=1;i<=m;++i){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		int len=r-l+1;
		int gc=(e-s)/(len-1);
		for(int j=s,k=l;j<=e&&k<=r;j+=gc,++k){
			a[k]+=j;
		}
	}
	
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans^=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}


