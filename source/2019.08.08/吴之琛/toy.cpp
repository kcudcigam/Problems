#include<bits/stdc++.h>
#define N 1010
#define INF 2000000
using namespace std;
int n,m,ans;
int a[N];
int f[N][N][2];
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			f[i][j][0]=INF;
			f[i][j][1]=INF;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++){
			if (j<=i-1) f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
			if (j) f[i][j][1]=f[i-1][j-1][0]+a[i];
		}
	for (int i=1;i<=n;i++)
		for (int j=0;j<=1;j++)
			if (f[n][i][j]<=m)
				ans=max(ans,i);
	printf("%d\n",ans);
	return 0;
}

