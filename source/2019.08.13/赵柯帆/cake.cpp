#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
long long f[310][310];
//int s1[310][310],s2[310][310];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	read(n);read(m);
	
	f[1][1]=1;
	if(n>m)swap(n,m);
	for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<i;k++){
					f[i][j]=((f[k][j]*f[i-k][j])%MOD+f[i][j])%MOD;
				}
				for(int k=1;k<j;k++){
					f[i][j]=((f[i][k]*f[i][j-k])%MOD+f[i][j])%MOD;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				if(j>=i){
					for(int k=1;k<i;k++){
						f[i][j]=((f[k][j]*f[i-k][j])%MOD+f[i][j])%MOD;
					}
					for(int k=1;k<j;k++){
						f[i][j]=((f[i][k]*f[i][j-k])%MOD+f[i][j])%MOD;
					}	
				}else{
					f[i][j]=f[j][i];
				}
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}

