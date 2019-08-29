#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
int a[500010],b[500010],c[500010];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);

	int n,m;
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	
	for(int i=1;i<=m;i++){
		int opt;
		read(opt);
		if(opt==1){
			int x,y,z;
			read(x);read(y);read(z);
			if(x==0)a[y]=z;
			else b[y]=z;
		}else{
			int l1,r1,l2,r2;
			read(l1);read(r1);read(l2);read(r2);
			
			int i=l1,j=l2,k=0;
			while(i<=r1&&j<=r2){
//				cout<<i<<' '<<j<<endl;
				if(a[i]<b[j]){
					c[++k]=a[i];
					i++;
				}else{
					c[++k]=b[j];
					j++;
				}
			}
			while(i<=r1){
				c[++k]=a[i];
				i++;
			}
			while(j<=r2){
				c[++k]=b[j];
				j++;
			}
			
			writeln(c[(k+1)/2]);
		}
	}
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4

*/


