#include<bits/stdc++.h>
using namespace std;
int n,m;
int q;
int a[3001][3001];
int f[3001]={0};
void read(int &t){
	int f=1;
	int x=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	t=x*f;
}
int dfs(int no,int mb,int mj){
	if(no==mb){
		return mj;
	}
	int s=INT_MAX;
	for(int i=1;i<=n;i++){
		if(a[no][i]&&f[i]==0){
			f[i]=1;
			s=min(s,dfs(i,mb,max(mj,a[no][i])));
			f[i]=0;
		}
	}
	return s;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x);
		read(y);
		read(z);
		if(a[x][y]==0){
			a[x][y]=z;
		}else{
			a[x][y]=min(a[x][y],z);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		read(x);
		read(y);
		f[x]=1;
		int g=dfs(x,y,0);
		if(g==INT_MAX){
			cout<<-1<<endl;
		}else{
			cout<<g<<endl;
		}
		f[x]=0;
	}
	return 0;
}


