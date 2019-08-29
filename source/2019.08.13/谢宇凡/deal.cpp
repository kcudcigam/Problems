#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x){
	char ch=getchar();
	x=0;T f=0;
	while (!isdigit(ch)){f|=ch=='-';ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

long long ans;
int n,X,maxn;
int a,b,c;

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(X);
	for (int i=1;i<=n;++i){
		read(a);read(b);read(c);
		ans=(ans+a*(b+c))%1000000007;
	}
	ans=ans/(n*n);
	printf("%lld\n",ans);
	
	return 0;
}


