#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int n,m;
long long f[310][310];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
    	x=(x<<1)+(x<<3)+(c&15);
    	c=getchar();
	}
	return x*w;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
    n=read();m=read();
    if(n>m)swap(n,m);
    f[1][1]=1;
    for(int i=1;i<=n;i++){
    	for(int j=1+(i==1);j<=m;j++){
    		if(i>j){f[i][j]=f[j][i];continue;}
    		for(int k=1;k<j;k++){
    			if(k<i)f[i][j]+=(f[k][j]*f[i-k][j])%mod;
    			f[i][j]+=(f[i][k]*f[i][j-k])%mod;
   			    f[i][j]%=mod;
			}
   		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
