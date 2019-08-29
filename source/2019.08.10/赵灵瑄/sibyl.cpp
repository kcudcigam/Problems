#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
int n,m,Q,u,v,t,x,y;
int f[3000][3000],a[300005];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
    read(n);read(m);read(Q);
    for(int i=1;i<=n;i++)
        f[i][i]=1;
    for(int i=1;i<=m;i++){
    	read(u);read(v);
    	f[u][v]=1;
    	f[v][u]=1;
	}
	for(int i=1;i<=Q;i++){
		read(t);
		if(t==0){
			read(x);
			cout<<a[x]<<endl;
		}
		if(t==1){
			read(x);read(y);
			for(int j=1;j<=n;j++)
			    if(f[x][j]==1)
			       a[j]=a[j]+y;
		}
	}
	return 0;
}


