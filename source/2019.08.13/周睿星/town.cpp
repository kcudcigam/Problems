#include<bits/stdc++.h>
using namespace std;
int f[2010][2010];
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}	
	return p*q;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int N=read();
	int k=N;
	N--;
	while(N--){
		int x=read(),y=read();
		f[x][y]=1;
		f[y][x]=1;
		for(int i=1;i<=k;++i){
			for(int j=1;j<=k;++j){
				if(i==y||j==x)
				break;
				f[y][x]=f[x][y]=max(f[x][y],f[x][i]+f[y][j]+1);
			}
		}
		for(int i=1;i<=k;++i){
			if(f[x][i])
			f[i][x]=f[x][i]=f[x][y];
		}
		for(int i=1;i<=k;++i){
			if(f[y][i])
			f[i][y]=f[y][i]=f[x][y];
		}
		cout<<f[x][y]<<endl;
	}
	return 0;
}
