#include<bits/stdc++.h>
using namespace std;
inline int read(){
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int a[500005],b[500005];
int c[500005*2];
int n,m;
inline void change(int x,int y,int z){
	if(x){
		b[y]=z;
	}
	else{
		a[y]=z;
	}return;
}
void work(int l,int r,int ll,int rr){
	int tot=0;
	for(int i=l;i<=r;++i){
		c[++tot]=a[i];
	}
	for(int i=ll;i<=rr;++i){
		c[++tot]=b[i];
	}sort(c+1,c+1+tot);
	printf("%d\n",c[(tot+1)/2]);
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	int op,L1,L2,R1,R2,x,y,z;
	for(int i=1;i<=m;++i){
		op=read();
		if(op==1){
			x=read(),y=read(),z=read();
			change(x,y,z);
		}
		else{
			L1=read(),R1=read(),L2=read(),R2=read();
			work(L1,R1,L2,R2);
		}
	}
	return 0;
}

