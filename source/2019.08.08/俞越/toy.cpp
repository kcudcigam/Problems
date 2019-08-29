#include<bits/stdc++.h>
#define LL long long 
#define mid (l+r>>1)
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1010;
int f[M][M];
int s[M][M];
int n,m,w[M];
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=n;i++) w[i]=read();
	memset(f,1,sizeof f);
	memset(s,1,sizeof s);
	for (int i=0;i<=n;i++) {
		f[i][0]=s[i][0]=0;
	}
	s[0][0]=f[0][0]=0; s[1][0]=f[1][0]=0; s[1][1]=f[1][1]=w[1];
	for (int j=1;j<=n;j++){
		for (int i=2;i<=n;i++){
			f[i][j]=s[i-2][j-1]+w[i];
			s[i][j]=f[i][j];
		}
		for (int i=1;i<=n;i++){
			s[i][j]=min(s[i][j],s[i-1][j]);
		}
	}
//	cout<<f[10][5]<<"\n";
//	cout<<f[2][2]<<"\n";
	
	for (int i=n;~i;i--){
		for (int j=1;j<=n;j++)
		if (f[j][i]<=m){
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}

