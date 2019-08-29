#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
const int N=305,p=1000000007;
int n,m,f[N][N];
void check(int &x,int y){x=(x+y<p) ? (x+y) : (x+y-p);}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=read();m=read();
	f[1][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		for (int k=1;k<i;k++)
		check(f[i][j],(ll)f[k][j]*f[i-k][j]%p);
		
		for (int k=1;k<j;k++)
		check(f[i][j],(ll)f[i][k]*f[i][j-k]%p);
	}
	printf("%d\n",f[n][m]);
	return 0;
}
