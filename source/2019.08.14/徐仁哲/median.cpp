#include<bits/stdc++.h>
#define N 500010
using namespace std;
template <typename T> void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	x*=f;
}
int n,m;
int a[N],b[N],c[N*2];
int vis,x,y,z,l1,r1,l2,r2;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		read(b[i]);
	for(int i=1;i<=m;i++){
		read(vis);
		if(vis==1){
			read(x);
			read(y);
			read(z);
			if(x==0) a[y]=z;
			else b[y]=z;
		}else{
			read(l1),read(r1),read(l2),read(r2);
			int len=0;
			for(int j=l1;j<=r1;j++){
				len++;
				c[len]=a[j];
			}
			for(int j=l2;j<=r2;j++){
				len++;
				c[len]=b[j];
			}
			sort(c+1,c+1+len);
			printf("%d\n",c[(len+1)/2]);
		}
	}
	return 0;
}
