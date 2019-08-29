#include<bits/stdc++.h>
long long mo=1000000007;
using namespace std;
int a[500001];
int b[500001];
int qz(int x,int y,int l,int r){
	int flag=1,mida,midb,now=0;
	int xx=x,yy=y,ll=l,rr=r;
	while(x<y&&l<r){
		mida=(x+y)/2;
		midb=(l+r)/2;
		if(mida-xx+midb-ll+2<=(yy-xx+rr-ll+3)/2){
			if(a[mida]>b[midb]){
				l=midb+1;
			}
			else{
				x=mida+1;
			}
			flag=0;
		}
		else{
			if(a[mida]>b[midb]){
				y=mida;
			}
			else{
				r=midb;
			}

		}
	}
	if(a[mida]>=b[midb]&&mida-xx+1+midb-ll+1>(yy-xx+rr-ll+3)/2||b[midb]>=a[mida]&&mida-xx+1+midb-ll+1==(yy-xx+rr-ll+3)/2)return b[midb];
	else return a[mida];

}
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int main(){

	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
	}
	int num1=1,num2=1;
	int typ,l,r,f,e,x,y;
	for(int i=1;i<=m;i++){
		read(typ);
		if(typ==1){
			read(l);read(x);read(y);
			if(l==0){
				a[x]=y;
			}
			else b[x]=y;
		}
		else{
			read(l);read(r);read(f);read(e);
			writeln(qz(l,r,f,e));
		}
	}
	return 0;
}


