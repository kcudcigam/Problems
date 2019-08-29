#include <iostream>
#include <cstdio>
using namespace std;

template <class T_> void read(T_ &x) {
	char ch;bool flag=false;x=0;
	while(!isdigit(ch=getchar()))
		(ch=='-')&&(flag=true);
	do{(x*=10)+=ch-'0';
	}while(isdigit(ch=getchar()));
	(flag)&&(x=-x);
} 
template <class T_> void print(T_ x) {
	(x<0)&&(putchar('0'),x=-x);
	if(x>9)print(x/10);
	putchar(x%10+'0');
}

int n;
int f[500005];
int s[500005];
int ans[500005];

int find(int x) <%return x==f[x]?x:(f[x]=find(f[x]));%>

int main(void) {
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	
	int q;
	read(n);read(q);
	for(int i=1;i<=n;++i)f[i]=i;
	while(q--) {
		int opt,a,b;
		read(opt);read(a);read(b);
		if(opt==1) {
			int f1=find(a),f2=find(b);
			if(f1!=f2) {
				f[a]=f2;
			}
		}
		else {
			int fa=find(a);
			for(int i=1;i<=n;++i)
				if(f[i]==fa)ans[i]+=b;
		}
	}
	for(int i=1;i<=n;++i) {
		print(ans[i]);putchar(' ');
	}
	
	fclose(stdin);
	fclose(stdout);
}
