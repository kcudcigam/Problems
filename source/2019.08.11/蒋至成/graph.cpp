#include<bits/stdc++.h>
using namespace std;
const int inf=1061109567;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int f[1001][1001];
int n,m,q;
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	read(n);read(m);read(q);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i){
		int x,y,z;
		read(x);read(y);read(z);
		f[x][y]=min(f[x][y],z);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			}
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		read(x);read(y);
		if(f[x][y]==inf)printf("%d\n",-1);
		else printf("%d\n",f[x][y]);
	}
	return 0;
}


