#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
vector<int>a[300005];
int n,m,i,j,k,l,s,d,f,r,yuan,yuanj;
void dfs(int x,int dep,int hui){
	if(dep>yuanj){
		yuan=x;
		yuanj=dep;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=hui){
			dfs(a[x][i],dep+1,x);
		}
	}
	return;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(i=1;i<n;i++){
		f=read();
		r=read();
		a[f].push_back(r);
		a[r].push_back(f);
		yuanj=0;
		yuan=f;
		dfs(f,0,0);
		l=yuan;
		yuanj=0;
		dfs(yuan,0,0);
		printf("%d\n",yuanj);
	} 
	return 0;
}
