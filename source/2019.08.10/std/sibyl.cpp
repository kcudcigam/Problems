#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
const int N = 301000;
int n,m,Q,u[N],v[N],d[N],val[N],tag[N];
vector<int> e[N];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);read(m);read(Q);
	for(int i=1;i<=m;i++){
		read(u[i]);read(v[i]);
		d[u[i]]++;d[v[i]]++;
	}
	for(int i=1;i<=m;i++)
		if(d[u[i]]<d[v[i]]) e[u[i]].push_back(v[i]);
		else e[v[i]].push_back(u[i]);
	while(Q--){
		int opt,x,y;read(opt);read(x);
		if(opt==0){
			int ans=val[x];
			for(int v:e[x]) ans+=tag[v];
			printf("%d\n",ans);
		}
		else{
			read(y);
			for(int v:e[x]) val[v]+=y;
			val[x]+=y;tag[x]+=y;
		}
	}
	return 0;
}
