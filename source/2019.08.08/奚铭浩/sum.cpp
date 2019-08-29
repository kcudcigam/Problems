#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[100010];
long long b[100010];
long long MAXX=-LONG_LONG_MAX;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		b[i]=b[i-1]+a[i];
	}
	
	for(int i=1;i<=n-2;++i){
		for(int j=i;j<=n-2;++j){
			for(int k=j+2;k<=n;++k){
				for(int l=k;l<=n;++l){
					long long s=b[j]-b[i-1]+b[l]-b[k-1];
					if(s>MAXX)MAXX=s;
				}
			}
		}
	}
	
	printf("%lld\n",MAXX);
	return 0;
}


