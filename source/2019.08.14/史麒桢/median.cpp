#include<bits/stdc++.h>
using namespace std;
int a[2][555555];
int c[555555];
template <typename T> void read(T &x){
	T f=1; x=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
}
template <typename T> void writing(T x){
	if (x>9){
		writing(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void write(T x){
	if (x<0){
		x=-x;
		putchar('-');
	}
	writing(x);
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	for (int i=1;i<=n;i++){
		read(a[0][i]);
	}
	for (int i=1;i<=n;i++){
		read(a[1][i]);
	}
	for (int i=1;i<=m;i++){
		int cz;
		read(cz);
		if (--cz){
			int l1,r1,l2,r2;
			read(l1);
			read(r1);
			read(l2);
			read(r2);
			int tot=r1+r2-l1-l2+2;
			int mid=(tot+1)>>1;
			while (mid--){
				if (l1>r1){
					c[mid]=a[1][l2++];
					continue;
				}
				if (l2>r2){
					c[mid]=a[0][l1++];
					continue;
				}
				if (a[0][l1]<a[1][l2]){
					c[mid]=a[0][l1++];
				}
				else {
					c[mid]=a[1][l2++];
				}
			}
			writeln(c[0]);
		}
		else {
			int x,y,z;
			read(x);
			read(y);
			read(z);
			a[x][y]=z;
		}
	}
	return 0;
}

