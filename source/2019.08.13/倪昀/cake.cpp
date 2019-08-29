#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const long long P=1000000007;
long long f[500][500];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    int n=read(),m=read();
    memset(f,0,sizeof(f));
    f[1][1]=1;
    fir(i,1,n)
        fir(j,1,m){
        	fir(k,1,i-1)f[i][j]+=(f[k][j]*f[i-k][j])%P;
        	fir(k,1,j-1)f[i][j]+=(f[i][k]*f[i][j-k])%P;
        	f[i][j]%=P;
		}
	cout<<f[n][m]<<endl;
	return 0;
}
