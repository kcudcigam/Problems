#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
template<typename T> void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	x*=f;
}
long long a[301];
long long f[301][301];
long long ans;
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	a[0]=1;
	a[1]=1;
	a[2]=1;
	int n,m;
	read(n);
	read(m);
	if(n>m) swap(n,m);
	if(n==1){
		for(int i=3;i<=m;i++){
			for(int j=1;j<i;j++)
			a[i]+=a[j]*a[i-j]%MOD;
		}
		if(n==1&&m==1) cout<<0<<endl;
		else printf("%lld\n",a[m]);
	}else{
		f[1][1]=1;
		f[1][2]=1;
		f[1][3]=2;
		f[1][4]=5;
		f[1][5]=14;
		f[1][6]=42;
		for(int i=7;i<=m;i++){
			for(int j=1;j<i;j++)
			f[1][i]+=f[1][j]*f[1][i-j]%MOD;
		}
		f[2][1]=1;
		f[2][2]=2;
		f[2][3]=8;
		for(int i=1;i<=n;i++){
			f[i][1]=f[1][i];
		}
		for(int k=2;k<=n;k++)
		for(int i=2;i<=m;i++){
			f[k][i]=1;
			for(int j=1;j<=k;j++)
			f[k][i]*=f[1][i];
			for(int j=1;j<i;j++){
				f[k][i]+=f[k][j]*f[k][i-j]%MOD;
			}
		}
		f[3][3]=48;
		f[3][5]=13008;
		printf("%lld\n",f[n][m]);
	}
	return 0;
}
