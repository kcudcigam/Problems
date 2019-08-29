#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[5000001];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long dc(long long l,long long r,long long a1,long long an){
	long long x;
	x=(an-a1)/(r-l);
	return x;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++){
		long long l,r,s,e;
		read(l);read(r);read(s);read(e);
		long long d;
		if(s==e){
			for(int j=l;j<=r;j++)a[j]++;
		}
		else {
			d=dc(l,r,s,e);
			for(int j=l;j<=r;j++){
				a[j]+=(s+(j-l)*d);
			}
		}
	}
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans^=a[i];
	}
	printf("%lld",ans);
}
