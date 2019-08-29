#include <iostream> 
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

template <class T_> void read(T_ &x) {
	char ch;bool flag=false;x=0;
	while(!isdigit(ch=getchar()));
		(ch=='-')&&(flag=true);
	do{(x*=10)+=ch-'0';
	}while(isdigit(ch=getchar()));
	(flag)&&(x=-x);
}

int a[1000005],b[1000005],c[1000005];

int main(void) {
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	
	int n,m;
	read(n);read(m);
	for(int i=1;i<=n;++i)
		read(a[i]);
	for(int i=1;i<=n;++i)
		read(b[i]);
	while(m--) {
		int opt;
		read(opt);
		if(opt==1) {
			int x,y,z;
			read(x);read(y);read(z);
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else {
			int l1,r1,l2,r2;
			read(l1);read(r1);read(l2);read(r2);
			int cnt=0;
			for(int i=l1;i<=r1;++i)c[++cnt]=a[i];
			for(int i=l2;i<=r2;++i)c[++cnt]=b[i];
			sort(c+1,c+1+cnt);
			printf("%d\n",c[cnt/2+1]);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}
