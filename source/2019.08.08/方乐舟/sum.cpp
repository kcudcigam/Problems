#include<bits/stdc++.h>
using namespace std;
int n;
long long ma;
long long a[100010],f[100010];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int dp(int x,int y){
	long long maa;
	for (int i=x;i<=y;i++){
		f[i]=a[i];
	}
	maa=f[x];
	for (int i=x+1;i<=y;i++){
		f[i]=max(f[i],f[i]+f[i-1]);
		maa=max(maa,f[i]);
	}
	return maa;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i]);
	}
	for (int i=2;i<=n-1;i++){
		if (dp(1,i-1)+dp(i+1,n)>ma) ma=dp(1,i-1)+dp(i+1,n);
	}
	printf("%lld\n",ma);
	return 0;
}


