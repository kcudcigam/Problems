#include <iostream>
#include <cstdio>
#include <cctype>
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
	(x<0)&&(putchar('-'),x=-x);
	if(x>9)print(x/10);
	putchar(x%10+'0');
}

int tot=0;
int go[1000005],net[1000005],fir[300005];

void Add(int u,int v) {
	go[++tot]=v;net[tot]=fir[u];fir[u]=tot;
}

int add[300005],t[300005];

int main(void) {
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	
	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=m;++i) {
		int u,v;
		read(u);read(v);
		Add(u,v);Add(v,u);
	}
	while(q--) {
		int opt;
		read(opt);
		if(opt==0) {
			int x;
			read(x);
			t[x]+=add[x];
			for(int i=fir[x];i;i=net[i]) {
				int y=go[i];
				t[y]+=add[x];
				t[y]+=add[y];
				if(add[y]==0)continue;
				for(int j=fir[y];j;j=net[j])
					t[go[j]]+=add[y];
				add[y]=0;
			}
			add[x]=0;
			print(t[x]);putchar('\n');
		}
		else {
			int x,y;
			read(x);read(y);
			add[x]+=y;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}
