#include<bits/stdc++.h>
using namespace std;
template <typename _Tp> inline _Tp read(_Tp&x){
    char c11=getchar(),minu=0;x=0;
    while(c11^'-'&&!isdigit(c11))c11=getchar();
	if(c11=='-')c11=getchar(),minu=1;
    while(isdigit(c11)){
    	x=x*10+c11-'0';
		c11=getchar();
	}
	if(minu)x=-x;
	return x;
}
const int maxn=1000+5;
int f[maxn][maxn];
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,q;
	read(n);
	read(m);
	read(q);
	memset(f,-1,sizeof(f));
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x);
		read(y);
		read(z);
	    f[x][y]=f[y][x]=z;	
	}
	for(int k=1;k<=n;k++)
	   for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)
	         if(f[i][k]>0&&f[k][j]>0){
	         	if(f[i][j]<0)f[i][j]=INT_MAX;
	         	f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			 }
	for(int i=1;i<=q;i++){
		int x,y;
		read(x);read(y);
		cout<<f[x][y]<<endl;
	}   
	return 0;
}


