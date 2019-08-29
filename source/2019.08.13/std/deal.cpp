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
const int N=1005,M=20005,p=1000000007;
int n,m,a[N],b[N],c[N],f[M];
void check(int &x,int y){x=(x+y<p) ? (x+y) : (x+y-p);}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		a[i]=read(),b[i]=(read()+1)*a[i],c[i]=(read()+1)*a[i];
	}
	f[0]=1;
	for (int i=n;i;i--){
		for (int j=a[i];j<m+a[i];j++) check(f[j],f[j-a[i]]);
		for (int j=m+a[i]-1;j>=b[i];j--) check(f[j],p-f[j-b[i]]);
	}
	for (int i=0;i<a[n];i++) f[i]=f[i+m];
	for (int i=1;i<=n;i++){
		for (int j=a[n]-1;j>=a[i];j--) check(f[j-a[i]],f[j]);
		for (int j=0;j+c[i]<a[n];j++) check(f[j],p-f[j+c[i]]);
	}
	printf("%d\n",f[0]);
	return 0;
}
