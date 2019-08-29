#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

ll num[maxn];
int n;
ll sum=-inf,tmp;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(rint i=1;i<=n;++i) read(num[i]);
	for(rint a=1;a<=n-1;++a)
		for(rint b=a;b<=n-1;++b)
			for(rint c=b+1;c<=n;++c)
				for(rint d=c;d<=n;++d){
					for(rint i=a;i<=b;++i) tmp+=num[i];
					for(rint j=c;j<=d;++j) tmp+=num[j];
					sum=max(sum,tmp);
					tmp=0;
				}
	cout<<sum;
	return 0;
}
